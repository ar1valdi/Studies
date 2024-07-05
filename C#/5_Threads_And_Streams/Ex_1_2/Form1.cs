using lab11;
using System.ComponentModel;

namespace Lab11_Forms
{
    public partial class Form1 : Form
    {
        static BackgroundWorker bgWorker;

        public Form1()
        {
            InitializeComponent();
        }

        private (long, long) ReadNK()
        {
            string nStr = (string)textBox2.Text;
            long n = long.Parse(nStr);
            string kStr = (string)textBox3.Text;
            long k = long.Parse(kStr);
            return (n, k);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string numStr = (string)textBox1.Text;
            int num = int.Parse(numStr);
            label1.Text = "";

            bgWorker = new BackgroundWorker();
            bgWorker.WorkerReportsProgress = true;
            bgWorker.DoWork += WorkerDoWork;
            bgWorker.ProgressChanged += WorkerProgressChanged;
            bgWorker.RunWorkerCompleted += WorkerRunWorkerCompleted;
            bgWorker.RunWorkerAsync(num);
        }

        private void WorkerProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            progressBar1.Value = e.ProgressPercentage;
        }

        private void WorkerDoWork(object sender, DoWorkEventArgs e)
        {
            if (e.Argument == null)
            {
                Console.WriteLine("no argumrnt");
                throw new Exception("No argument");
            }
            Console.WriteLine("Entered");
            int n = (int)e.Argument;
            long resultPrev = 1;
            long result = 1;
            for (int i = 2; i < n; i++)
            {
                long next = result + resultPrev;
                resultPrev = result;
                result = next;
                Thread.Sleep(500);
                bgWorker.ReportProgress((int)(((double)(i + 1) * 100.0) / (double)n));
            }
            e.Result = result;
        }
        private void WorkerRunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Result == null)
            {
                throw new Exception("No result");
            }
            Int64 result = (Int64)e.Result;
            label1.Text = result.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            (double, double) data = ReadNK();
            Zad2.Go(data.Item1, data.Item2, false);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            (double, double) data = ReadNK();
            Zad1.Go(data.Item1, data.Item2, false);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            (double, double) data = ReadNK();
           Zad3.Go(data.Item1, data.Item2, false);
        }
    }
}