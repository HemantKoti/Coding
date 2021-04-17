using System;

namespace SubsetSum
{
    class TopDown
    {
        internal static int SubsetSum(int[][] memo, int[] numbers, int target, int n)
        {
            if (target == 0)
                return 1;

            if (n <= 0)
                return 0;

            if (memo[n][target] != -1)
                return memo[n][target];

            return memo[n][target] = (numbers[n - 1] > target) ? SubsetSum(memo, numbers, target, n - 1) :
                SubsetSum(memo, numbers, target, n - 1) | SubsetSum(memo, numbers, target - numbers[n - 1], n - 1);
        }
    }

    class BottomUp
    {
        internal static int SubsetSum(int[][] memo, int[] numbers, int target, int n)
        {
            for (int i = 0; i <= n; i++)
                memo[i][0] = 1;

            for (int i = 0; i <= target; i++)
                memo[0][i] = 0;

            for (int i = 1; i <= n; i++)            
                for (int j = 1; j <= target; j++)                
                    memo[i][j] = j < numbers[i - 1] ? memo[i - 1][j] : memo[i - 1][j] | memo[i - 1][j - numbers[i - 1]];
                           
            return memo[n][target];
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

            int target = 9;
            int[] numbers = new int[] { 3, 34, 4, 12, 5, 2 };
            int[][] memo = new int[numbers.Length + 1][];
            for (int i = 0; i < memo.Length; i++)
            {
                memo[i] = new int[target + 1];
                Array.Fill(memo[i], -1);
            }

            Console.WriteLine("Output: " + TopDown.SubsetSum(memo, numbers, target, numbers.Length));
            Console.WriteLine("Output: " + BottomUp.SubsetSum(memo, numbers, target, numbers.Length));
        }
    }
}
