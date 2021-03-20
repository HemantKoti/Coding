using System;
using System.Collections.Generic;

namespace CanSum
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> numbers = new List<int>() { 5, 4, 3, 7, 1, 2, 6 };
            Dictionary<int, bool> memo = new Dictionary<int, bool>();
            int target = 27;

            Console.WriteLine(CanSum(target, numbers, memo));
        }

        private static bool CanSum(int target, List<int> numbers, Dictionary<int, bool> memo)
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

            memo.Add(target, false);

            return false;
        }
    }
}
