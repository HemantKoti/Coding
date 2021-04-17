using System;
using System.Collections.Generic;

namespace CanSum
{
    // Time: O(target * n) and Space: O(target)
    // n = numbers array length 
    class TopDown
    {
        internal static bool CanSum(int target, List<int> numbers, Dictionary<int, bool> memo)
        {
            if (memo.ContainsKey(target))
                return memo[target];

            if (target == 0)
                return true;

            if (target < 0)
                return false;

            for (int i = 0; i < numbers.Count; i++)
                if (CanSum(target - numbers[i], numbers, memo))
                    return true;

            memo[target] = false;
            return memo[target];
        }
    }

    class BottomUp
    {
        internal static bool CanSum(int target, List<int> numbers, Dictionary<int, bool> memo) { 
            
            return false;
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
            Dictionary<int, bool> memo = new Dictionary<int, bool>();
            int target = 27;

            Console.WriteLine(TopDown.CanSum(target, numbers, memo));

            Console.WriteLine(BottomUp.CanSum(target, numbers, memo));
        }
    }
}
