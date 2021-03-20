using System;

namespace Knapsack
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] val = new int[] { 60, 100, 120 };
            int[] wt = new int[] { 10, 20, 30 };

            int W = 50;
            int N = val.Length;

            Console.WriteLine(KnapSack(W, wt, val, N));
        }

        private static int KnapSack(int W, int[] wt, int[] val, int N)
        {
            int[,] dp = new int[N + 1, W + 1];

            for (int i = 0; i < N + 1; i++)
                for (int j = 0; j < W + 1; j++)
                    dp[i, j] = -1;

            return KnapSackUtil(W, wt, val, N, dp);
        }

        private static int KnapSackUtil(int W, int[] wt, int[] val, int N, int[,] dp)
        {
            if (N == 0 || W == 0)
                return 0;

            if (dp[N, W] != -1)
                return dp[N, W];

            if (wt[N - 1] > W)
            {
                return dp[N, W] = KnapSackUtil(W, wt, val, N - 1, dp);
            }
            else
            {
                return dp[N, W] = Math.Max(val[N - 1] + KnapSackUtil(W - wt[N - 1], wt, val, N - 1, dp),
                    KnapSackUtil(W, wt, val, N - 1, dp));
            }
        }
    }
}
