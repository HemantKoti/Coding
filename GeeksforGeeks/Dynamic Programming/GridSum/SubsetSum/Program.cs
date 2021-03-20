using System;

namespace SubsetSum
{
    class Program
    {
        private static int SubsetSum(int[][] memo, int[] numbers, int target, int n)
        {
            if (target == 0)
                return 1;

            if (n <= 0)
                return 0;

            if (memo[n][target] != -1)
                return memo[n][target];

            if (numbers[n - 1] > target)
                memo[n][target] = SubsetSum(memo, numbers, target, n - 1);
            else
                memo[n][target] = SubsetSum(memo, numbers, target, n - 1) |
                    SubsetSum(memo, numbers, target - numbers[n - 1], n - 1);

            return memo[n][target];
        }

        static void Main(string[] args)
        {
            int target = 9;
            int[] numbers = new int[] { 3, 34, 4, 12, 5, 2 };
            int[][] memo = new int[numbers.Length + 1][];
            for (int i = 0; i < memo.Length; i++)
            {
                memo[i] = new int[target + 1];
                Array.Fill(memo[i], -1);
            }

            Console.WriteLine("Output: " + SubsetSum(memo, numbers, target, numbers.Length));
        }
    }
}
