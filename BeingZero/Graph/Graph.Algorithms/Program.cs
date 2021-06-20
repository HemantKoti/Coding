using System;

namespace Graph.Algorithms
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args is null)
            
                throw new ArgumentNullException(nameof(args));            

            Graph g = new(4);

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

            g = new Graph(6);

            g.AddEdge(5, 2);
            g.AddEdge(5, 0);
            g.AddEdge(4, 0);
            g.AddEdge(4, 1);
            g.AddEdge(2, 3);
            g.AddEdge(3, 1);

            // Topological Sort
            Console.WriteLine();
            Console.WriteLine("Topological Sorting");
            TopologicalSort tps = new();
            tps.TopSort(g);
        }
    }
}
