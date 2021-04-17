using System;
using System.Collections.Generic;

namespace AllConstruct
{
    class TopDown
    {
        internal static List<List<string>> AllConstruct(string target, IList<string> wordBank, Dictionary<string, List<List<string>>> memo)
        {
            if (memo.ContainsKey(target))
                return memo[target];

            if (string.IsNullOrEmpty(target))
                return new List<List<string>>();

            List<List<string>> result = new();

            foreach (string word in wordBank)
            {
                if (target.IndexOf(word) == 0)
                {
                    string suffix = target[word.Length..];
                    List<List<string>> ways = AllConstruct(suffix, wordBank, memo);
                    if (ways.Count == 0)
                    {
                        result.Add(new List<string> { word });
                    }
                    for (int i = 0; i < ways.Count; i++)
                    {
                        ways[i].Insert(0, word);
                        result.Add(ways[i]);
                    }
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

            Dictionary<string, List<List<string>>> memo = new();
            List<List<string>> result = TopDown.AllConstruct("purple", new List<string> { "purp", "p", "ur", "le", "purpl" }, memo);
            foreach (List<string> _result in result)
                Console.WriteLine(string.Join(" ", _result));
        }
    }
}
