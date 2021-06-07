using System;
using System.Collections.Generic;

namespace Trie
{
    // Trie node
    public class TrieNode
    {
        const int ALPHABET_SIZE = 26;

        public TrieNode[] children = new TrieNode[ALPHABET_SIZE];

        public bool isEndOfWord;

        public TrieNode()
        {
            isEndOfWord = false;
            for (int i = 0; i < ALPHABET_SIZE; i++)
                children[i] = null;
        }
    }

    public class Trie
    {
        const int ALPHABET_SIZE = 26;
        TrieNode root;

        public Trie()
        {
            root = new TrieNode();
        }

        public void Insert(string key)
        {
            TrieNode pCrawl = root;

            foreach (char c in key)
            {
                int index = c - 'a';
                if (pCrawl.children[index] == null)
                    pCrawl.children[index] = new TrieNode();

                pCrawl = pCrawl.children[index];
            }

            pCrawl.isEndOfWord = true;
        }

        public bool Search(string key)
        {
            TrieNode pCrawl = root;

            foreach (char c in key)
            {
                int index = c - 'a';

                if (pCrawl.children[index] == null)
                    return false;

                pCrawl = pCrawl.children[index];
            }

            return (pCrawl != null && pCrawl.isEndOfWord);
        }

        // Returns true if root has no children, else false
        public bool IsEmpty(TrieNode root)
        {
            for (int i = 0; i < ALPHABET_SIZE; i++)
                if (root.children[i] == null)
                    return false;

            return true;
        }

        public void AutoSuggestUtil(TrieNode root, ref List<string> result, string word)
        {
            if (root.isEndOfWord)
                result.Add(word);

            for (int i = 0; i < ALPHABET_SIZE; i++)
            {
                if (root.children[i] != null)
                {
                    char ch = 'a';
                    ch += (char)i;
                    string newWord = word + ch.ToString();
                    AutoSuggestUtil(root.children[i], ref result, newWord);
                }
            }
        }

        public List<string> AutoSuggest(string prefix)
        {
            TrieNode pCrawl = root;
            List<string> result = new List<string>();

            foreach (char c in prefix)
            {
                int index = c - 'a';
                if (pCrawl.children[index] == null)
                    return null;

                pCrawl = pCrawl.children[index];
            }

            AutoSuggestUtil(pCrawl, ref result, prefix);
            return result;
        }

        public bool StartsWith(string prefix)
        {
            TrieNode pCrawl = root;
            foreach (char c in prefix)
            {
                int index = c - 'a';
                if (pCrawl.children[index] == null)
                    return false;
                pCrawl = pCrawl.children[index];
            }

            return true;
        }

        public TrieNode Remove(TrieNode root, string key, int depth)
        {
            if (root == null)
                return null;

            if (depth == key.Length)
            {
                if (root.isEndOfWord)
                    root.isEndOfWord = false;

                if (IsEmpty(root))
                    root = null;

                return root;
            }

            int index = key[depth] - 'a';
            root.children[index] = Remove(root.children[index], key, depth + 1);

            if (IsEmpty(root) && !root.isEndOfWord)
                root = null;

            return root;
        }
    }

    public class Program
    {
        static void Main()
        {
            string[] words = { "the", "a", "there", "answer", "any", "by", "bye", "their" };

            string[] output = { "Not present in trie", "Present in trie" };

            Trie trie = new();

            // Insert
            for (int i = 0; i < words.Length; i++)
                trie.Insert(words[i]);

            // Search
            if (trie.Search("the") == true)
                Console.WriteLine("the --- " + output[1]);
            else Console.WriteLine("the --- " + output[0]);

            if (trie.Search("these") == true)
                Console.WriteLine("these --- " + output[1]);
            else Console.WriteLine("these --- " + output[0]);

            if (trie.Search("thaw") == true)
                Console.WriteLine("thaw --- " + output[1]);
            else Console.WriteLine("thaw --- " + output[0]);

            // AutoSuggest
            Console.WriteLine();
            Console.WriteLine("AutoSuggest");
            foreach (string word in trie.AutoSuggest("th"))
                Console.WriteLine(word);

            Console.WriteLine();
            foreach (string word in trie.AutoSuggest("a"))
                Console.WriteLine(word);
        }
    }
}
