using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11
{
    internal class Zad3
    {
        async public static Task Go(double N, double K, bool log)
        {
            Task<double> t = CalcUp(N, K, log);
            Task<double> t2 = CalcDown(N, K, log);

            await Task.WhenAll(t, t2);

            if (log) Console.WriteLine("Result up: " + t.Result);
            if (log) Console.WriteLine("Result down: " + t2.Result);
            MessageBox.Show($"ZAD3 Result: {t.Result / t2.Result}");
        }

        async static Task<double> CalcUp(double N, double K, bool log = false)
        {
            return await Task<double>.Run(async () =>
            {
                double res = 1;
                for (int i = 0; i < K; i++)
                {
                    if (log) Console.WriteLine(N - i);
                    res *= N - i;
                    await Task.Delay(100);
                }
                if (log) Console.WriteLine(res);
                return res;
            });
        }

        async static Task<double> CalcDown(double N, double K, bool log = false)
        {
            return await Task<double>.Run(async () =>
            {
                double res = 1;
                for (int i = 2; i <= K; i++)
                {
                    if (log) Console.WriteLine(i);
                    res *= i;
                    await Task.Delay(80);
                }
                if (log) Console.WriteLine(res);
                return res;
            });
        }
    }
}
