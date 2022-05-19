using System;

namespace Problem176
{
    internal class Program
    {
        private static int Max(int[] a)
        {
            int len = a.Length;
            int max = a[0];
            for (int i = 1; i < len; i++)
            {
                if (a[i] > max) max = a[i];
            }
            return max;
        }

        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(massiv[i]);
            }
            int max = Max(a);
            int say = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == max) say++;
            }
            Console.WriteLine(say);
        }
    }
}
