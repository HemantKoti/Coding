using System;
using System.Collections.Generic;

namespace Graph
{
    class Graph
    {
        private int V;
        List<int>[] adjList;

        public Graph(int V)
        {
            this.adjList = new List<int>[V];
            for (int i = 0; i < V; i++)
                adjList[i] = new List<int>();

            this.V = V;
        }

        public void AddEdge(int x, int y)
        {
            this.adjList[x].Add(y);
        }

        public void BFS(int source)
        {
            bool[] visited = new bool[this.V];
            for (int i = 0; i < this.V; i++)
                visited[i] = false;

            Queue<int> queue = new Queue<int>();
            visited[source] = true;

            queue.Enqueue(source);

            while (queue.Count != 0)
            {
                source = queue.Dequeue();
                Console.Write(source + " ");

                List<int> adjacent = this.adjList[source];

                foreach (int vertex in adjacent)
                {
                    if (!visited[vertex])
                    {
                        visited[vertex] = true;
                        queue.Enqueue(vertex);
                    }
                }
            }
        }

        private void DFSRecursiveUtil(int source, bool[] visited)
        {
            visited[source] = true;
            Console.Write(source + " ");

            List<int> vertexList = this.adjList[source];
            foreach (int vertex in vertexList)
            {
                if (!visited[vertex])
                    DFSRecursiveUtil(vertex, visited);
            }
        }

        public void DFSRecursive(int source)
        {
            bool[] visited = new bool[this.V];
            DFSRecursiveUtil(source, visited);
        }

        private void DFSIterativeUtil(int source, bool[] visited)
        {
            Stack<int> stack = new Stack<int>();

            stack.Push(source);

            while (stack.Count > 0)
            {
                source = stack.Pop();

                if (!visited[source])
                {
                    Console.Write(source + " ");
                    visited[source] = true;
                }

                foreach (int v in this.adjList[source])
                {
                    if (!visited[v])
                        stack.Push(v);
                }
            }
        }

        public void DFSIterative(int source)
        {
            bool[] visited = new bool[this.V];
            Array.Fill(visited, false);

            DFSIterativeUtil(source, visited);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Graph g = new Graph(4);

            g.AddEdge(0, 1);
            g.AddEdge(0, 2);
            g.AddEdge(1, 2);
            g.AddEdge(2, 0);
            g.AddEdge(2, 3);
            g.AddEdge(3, 3);

            g.BFS(2);
            Console.WriteLine();

            g.DFSRecursive(2);
            Console.WriteLine();

            g.DFSIterative(2);
            Console.WriteLine();
        }
    }
}
