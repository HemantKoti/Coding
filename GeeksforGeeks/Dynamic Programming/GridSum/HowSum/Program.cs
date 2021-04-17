using System;
using System.Collections.Generic;

namespace HowSum
{
    // Time: O(target * target * n) and Space: O(target * target)
    // n = numbers array length 
    class TopDown
    {
        internal static List<int> HowSum(int target, List<int> numbers, Dictionary<int, List<int>> memo)
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

            memo[target] = result;
            return memo[target];
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

            List<int> numbers = new List<int>() { 5, 4, 3, 7, 1, 2, 6 };
            Dictionary<int, List<int>> memo = new Dictionary<int, List<int>>();
            int target = 27;

            Console.WriteLine(string.Join(" ", TopDown.HowSum(target, numbers, memo).ToArray()));
        }
    }
}
