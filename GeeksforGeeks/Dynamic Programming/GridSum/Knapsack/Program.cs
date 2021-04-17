using System;

namespace Knapsack
{
    // Time: O(target * n) and Space: O(target)
    // n = numbers array length 
    class TopDown
    {
        internal static int KnapSack(int W, int[] wt, int[] val, int N)
        {
            int[][] dp = new int[N + 1][];

            for (int i = 0; i <= N; i++)
            {
                dp[i] = new int[W + 1];
                Array.Fill(dp[i], -1);
            }

            return KnapSackUtil(W, wt, val, N, dp);
        }

        private static int KnapSackUtil(int W, int[] wt, int[] val, int N, int[][] dp)
        {
            if (N == 0 || W == 0)
                return 0;

            if (dp[N][W] != -1)
                return dp[N][W];

            return dp[N][W] = (wt[N - 1] > W) ? KnapSackUtil(W, wt, val, N - 1, dp) :
                 Math.Max(val[N - 1] + KnapSackUtil(W - wt[N - 1], wt, val, N - 1, dp), KnapSackUtil(W, wt, val, N - 1, dp));
        }
    }

    class BottomUp
    {
        internal static int KnapSack(int W, int[] wt, int[] val, int N)
        {
            int[][] dp = new int[N + 1][];
   
            for (int i = 0; i <= N; i++)
            {
                dp[i] = new int[W + 1];
                for (int j = 0; j <= W; j++)
                {
                    if (i == 0 || j == 0)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = j < wt[i - 1] ? dp[i - 1][j] : Math.Max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
                }
            }

            return dp[N][W];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            if (args is null)
            {
                throw new ArgumentNullException(nameof(args));
            }

            int[] val = new int[] { 60, 100, 120 };
            int[] wt = new int[] { 10, 20, 30 };

            int W = 50;
            int N = val.Length;

            Console.WriteLine(TopDown.KnapSack(W, wt, val, N));

            Console.WriteLine(BottomUp.KnapSack(W, wt, val, N));
        }
    }
}
