using System;
using System.Collections.Generic;

namespace BestSum
{
    // Time: O(target * target * n) and Space: O(target * target)
    // n = numbers array length 
    class Program
    {
        class TopDown
        {
            internal static List<int> BestSum(int target, List<int> numbers, Dictionary<int, List<int>> memo)
            {
                if (memo.ContainsKey(target))
                    return memo[target];

                if (target == 0)
                    return new List<int>();

                if (target < 0)
                    return null;

                List<int> shortestCombination = null;

                for (int i = 0; i < numbers.Count; i++)
                {
                    int remainder = target - numbers[i];
                    List<int> result = BestSum(remainder, numbers, memo);
                    if (result != null)
                    {
                        result.Add(numbers[i]);

                        if (shortestCombination == null || shortestCombination.Count > result.Count)
                            shortestCombination = result;

                        //memo[target] = shortestCombination;
                        //return memo[target];
                    }
                }

                memo[target] = shortestCombination;
                return memo[target];
            }
        }

        class BottomUp
        {

        }

        static void Main(string[] args)
        {
            if (args is null)
            {
                throw new ArgumentNullException(nameof(args));
            }

            List<int> numbers = new List<int>() { 5, 6, 5, 1 };
            Dictionary<int, List<int>> memo = new Dictionary<int, List<int>>();
            int target = 11;

            List<int> result = TopDown.BestSum(target, numbers, memo);
            Console.WriteLine(string.Join(" ", result.ToArray()));
        }       
    }
}
