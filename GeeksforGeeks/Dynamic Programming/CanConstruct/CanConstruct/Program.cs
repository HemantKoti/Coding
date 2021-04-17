using System;
using System.Collections.Generic;

namespace CanConstruct
{
    class TopDown
    {
        internal static bool CanConstruct(string target, IList<string> wordBank, Dictionary<string, bool> memo)
        {

            if (memo.ContainsKey(target))
                return memo[target];

            if (String.IsNullOrEmpty(target))
                return true;

            foreach (string word in wordBank)
            {
                if (target.IndexOf(word) == 0)
                {
                    string suffix = target[word.Length..];
                    if (CanConstruct(suffix, wordBank, memo))
                    {
                        if (!memo.ContainsKey(target))
                            memo[target] = true;
                        return memo[target];
                    }

                }
            }

            memo[target] = false;
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

            Dictionary<string, bool> memo = new Dictionary<string, bool>();
            Console.WriteLine(TopDown.CanConstruct("catsandog", new List<string> { "cats", "dog", "sand", "and", "cat" }, memo));   
        }
    }
}
