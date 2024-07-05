using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11
{
    internal class Zad2
    {
        delegate double CalculateDelegate(double N, double K, bool log);
        public async static void Go(double N, double K, bool log=false)
        {
            CalculateDelegate numeratorDelegate = CalcUpTask;
            CalculateDelegate denominatorDelegate = CalcDownTask;

            try
            {
                IAsyncResult numeratorResult = numeratorDelegate.BeginInvoke(N, K, log, null, null);
                IAsyncResult denominatorResult = denominatorDelegate.BeginInvoke(N, K, log, null, null);

                double up = numeratorDelegate.EndInvoke(numeratorResult);
                double down = denominatorDelegate.EndInvoke(denominatorResult);
                MessageBox.Show($"ZAD2 Result: {up / down}");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        static double CalcUpTask(double N, double K, bool log = false)
        {
            double result = 1;
            for (int i = 0; i < K; i++)
            {
                result *= N - i;
            }
            return result;
        }

        static double CalcDownTask(double N, double K, bool log = false)
        {
            double result = 1;
            for (int i = 1; i <= K; i++)
            {
                result *= i;
            }
            return result;
        }
    }
}
