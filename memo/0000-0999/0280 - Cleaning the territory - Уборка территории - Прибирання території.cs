using System;

namespace Problem280
{
    internal class Program
    {
        private static long EBOB(long x, long y)
        {
            while (x*y != 0)
            {
                if (x < y) y = y%x;
                else x = x%y;
            }
            return x + y;
        }

        public static void Main(string[] args)
        {
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            long n = long.Parse(massiv[0]);
            long m = long.Parse(massiv[1]);
            Console.WriteLine(EBOB(n, m));
        }
    }
}
