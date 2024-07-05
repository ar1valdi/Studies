using System;
using System.Net.Sockets;
using System.Reflection;
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

class Client
{
    string name;
    int sentMsgs;
    private TcpClient client;
    private NetworkStream stream;

    public Client(string name, string ipAddress, int port)
    {
        this.name = name;
        this.sentMsgs = 0;
        client = new TcpClient(ipAddress, port);
        stream = client.GetStream();
        Console.WriteLine("Client name: " + name);
        Console.WriteLine("Connected to server");
    }

    public async Task StartAsync()
    {
        while (true)
        {
            CustomObject obj = new CustomObject { 
                clientName = name,
                msgNum = ++sentMsgs,
                dateTime = DateTime.Now
            };
            Console.WriteLine("Sending object: " + obj);

            byte[] data = JsonSerializer.SerializeToUtf8Bytes(obj);
            byte[] length = BitConverter.GetBytes(data.Length);

            await stream.WriteAsync(length, 0, length.Length);
            await stream.WriteAsync(data, 0, data.Length);

            byte[] lengthBuffer = new byte[4];
            await stream.ReadAsync(lengthBuffer, 0, 4);
            int responseLength = BitConverter.ToInt32(lengthBuffer, 0);

            byte[] responseBuffer = new byte[responseLength];
            await stream.ReadAsync(responseBuffer, 0, responseLength);

            CustomObject receivedObj = JsonSerializer.Deserialize<CustomObject>(responseBuffer);
            Console.WriteLine("Received object: " + receivedObj);
            CompareObjects(obj, receivedObj);

            await Task.Delay(2000);
        }
    }
    public static void CompareObjects(object obj1, object obj2)
    {
        var fields = obj1.GetType().GetFields(BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance);

        foreach (var field in fields)
        {
            var value1 = field.GetValue(obj1);
            var value2 = field.GetValue(obj2);

            if (!Equals(value1, value2))
            {
                string dType = field.Name;
                dType = dType.Substring(1, dType.IndexOf('>')-1);
                Console.WriteLine($"Difference in '{dType}': SENT: {value1} - RECV: {value2}");
            }
        }
    }

    static async Task Main(string[] args)
    {
        string name = "Client " + new Random().NextInt64(1, 100);
        Client client = new Client(name, "127.0.0.1", 5000);
        await client.StartAsync();
    }
}
