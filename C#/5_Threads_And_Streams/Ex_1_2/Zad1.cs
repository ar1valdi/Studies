using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11
{
    internal class Zad1
    {
        public static void Go(double N, double K, bool log)
        {
            //Task task = Task.Run(() => CalcUp(N, K, log));
            //Task task2 = Task.Run(() => CalcDown(K, log));
            //task.Wait();
            //task2.Wait();

            Task<double> taskRes = Task.Run(() => CalcUp(N, K, log));
            Task<double> taskRes2 = Task.Run(() => CalcDown(K, log));
            double up = taskRes.Result;
            double down = taskRes2.Result;
            MessageBox.Show($"ZAD1 Result: {up / down}");
        }

        static double CalcUp(double N, double K, bool log = false)
        {
            double res = 1;
            for (int i = 0; i < K; i++)
            {
                if (log) Console.WriteLine(N - i);
                res *= N - i;
                Thread.Sleep(100);
            }
            if (log) Console.WriteLine(res);
            return res;
        }

        static double CalcDown(double K, bool log = false)
        {
            double res = 1;
            for (int i = 2; i <= K; i++)
            {
                if (log) Console.WriteLine(i);
                res *= i;
            }
            if (log) Console.WriteLine(res);
            return res;
        }
    }
}
