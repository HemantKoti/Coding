using System;
using System.Collections.Generic;

namespace BestSum
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> numbers = new List<int>() { 5, 4, 3, 7, 1, 2, 6 };
            Dictionary<int, List<int>> memo = new Dictionary<int, List<int>>();
            int target = 27;

            List<int> result = BestSum(target, numbers, memo);
            if (result != null)
            {
                foreach (int _result in result)
                    Console.Write(_result + " ");
            }
        }

        private static List<int> BestSum(int target, List<int> numbers, Dictionary<int, List<int>> memo)
        {
            if (memo.ContainsKey(target))
                return memo[target];

            if (target == 0)
                return new List<int>();

            if (target < 0)
                return null;

            List<int> result = null;
            List<int> shortestCombination = null;

            for (int i = 0; i < numbers.Count; i++)
            {
                int remainder = target - numbers[i];
                result = BestSum(remainder, numbers, memo);
                if (result != null)
                {
                    result.Add(numbers[i]);

                    if (shortestCombination == null || shortestCombination.Count > result.Count)
                        shortestCombination = result;

                    memo[target] = result;
                    return memo[target];
                }
            }

            memo[target] = null;
            return memo[target];
        }
    }
}
