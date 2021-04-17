using System;
using System.Collections.Generic;

namespace CountConstruct
{
    class TopDown
    {
        internal static int CountConstruct(string target, IList<string> wordBank, Dictionary<string, int> memo)
        {
            if (memo.ContainsKey(target))
                return memo[target];

            if (String.IsNullOrEmpty(target))
                return 1;

            int result = 0;

            foreach (string word in wordBank)
            {
                if (target.IndexOf(word) == 0)
                {
                    string suffix = target[word.Length..];
                    result += CountConstruct(suffix, wordBank, memo);
                }
            }

            memo[target] = result;
            return result;
        }
    }
    class Program
    {        
        static void Main(string[] args)
        {
            Dictionary<string, int> memo = new Dictionary<string, int>();
            Console.WriteLine(TopDown.CountConstruct("catsanddog", new List<string> { "cats", "dog", "sand", "and", "cat" }, memo));
        }
    }
}
