using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;
using System.Threading;
using System.Threading.Tasks;

public class CustomObject
{
    public string clientName { get; set; }
    public int msgNum { get; set; }
    public DateTime dateTime { get; set; }
    override public string ToString()
    {
        return $"{{name={clientName},msgNum={msgNum},dateTime={dateTime}}}";
    }
}

class Server
{
    private TcpListener listener;

    public Server(string ipAddress, int port)
    {
        listener = new TcpListener(IPAddress.Parse(ipAddress), port);
        listener.Start();
        Console.WriteLine($"Server started and listening on {ipAddress}:{port}");
    }

    public async Task StartAsync()
    {
        while (true)
        {
            TcpClient client = await listener.AcceptTcpClientAsync();
            Console.WriteLine("Client connected");
            _ = Task.Run(() => HandleClientAsync(client));
        }
    }

    private async Task HandleClientAsync(TcpClient client)
    {
        NetworkStream stream = client.GetStream();

        try
        {
            while (true)
            {
                byte[] lengthBuffer = new byte[4];
                await stream.ReadAsync(lengthBuffer, 0, 4);
                int length = BitConverter.ToInt32(lengthBuffer, 0);

                byte[] dataBuffer = new byte[length];
                await stream.ReadAsync(dataBuffer, 0, length);

                CustomObject obj = JsonSerializer.Deserialize<CustomObject>(dataBuffer);
                Console.WriteLine("Received object with data: " + obj);
                
                obj.dateTime = DateTime.Now.AddYears(obj.msgNum);
                
                Console.WriteLine("Sending object: " + obj);

                byte[] responseData = JsonSerializer.SerializeToUtf8Bytes(obj);
                byte[] responseLength = BitConverter.GetBytes(responseData.Length);
                await stream.WriteAsync(responseLength, 0, responseLength.Length);
                await stream.WriteAsync(responseData, 0, responseData.Length);
            }
        }
        catch (Exception e)
        {
            Console.WriteLine("Client disconnected: " + e.Message);
        }
        finally
        {
            client.Close();
        }
    }

    static async Task Main(string[] args)
    {
        Server server = new Server("127.0.0.1", 5000);
        await server.StartAsync();
    }
}
