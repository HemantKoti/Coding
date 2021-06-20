using System;
using System.Collections.Generic;

namespace Graph.Algorithms
{
    internal class TopologicalSort
    {
        public void TopSort(Graph graph)
        {
            Stack<int> stack = new();
            bool[] visited = new bool[graph.V];

            for (int i = 0; i < graph.V; i++)
                visited[i] = false;

            for (int i = 0; i < graph.V; i++)
                if (!visited[i])
                    TopSortUtil(i, visited, ref stack, graph);

            foreach (int vertex in stack)
                Console.Write(vertex + " ");
        }

        private void TopSortUtil(int v, bool[] visited, ref Stack<int> stack, Graph graph)
        {
            visited[v] = true;

            foreach (int vertex in graph.adjList[v])
                if (!visited[vertex])
                    TopSortUtil(vertex, visited, ref stack, graph);

            stack.Push(v);
        }
    }
}
