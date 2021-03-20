using System;
using System.Collections.Generic;

namespace HowSum
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> numbers = new List<int>() { 5, 4, 3, 7, 1, 2, 6 };
            Dictionary<int, List<int>> memo = new Dictionary<int, List<int>>();
            int target = 27;

            List<int> result = HowSum(target, numbers, memo);
            if (result != null)
            {
                foreach (int _result in result)
                    Console.Write(_result + " ");
            }
        }

        private static List<int> HowSum(int target, List<int> numbers, Dictionary<int, List<int>> memo)
        {
            if (memo.ContainsKey(target))
                return memo[target];

            if (target == 0)
                return new List<int>();

            if (target < 0)
                return null;

            List<int> result = null;

            for (int i = 0; i < numbers.Count; i++)
            {
                int remainder = target - numbers[i];
                result = HowSum(remainder, numbers, memo);
                if (result != null)
                {
                    result.Add(numbers[i]);
                    memo[target] = result;
                    return memo[target];
                }
            }

            memo[target] = null;
            return memo[target];
        }
    }
}
