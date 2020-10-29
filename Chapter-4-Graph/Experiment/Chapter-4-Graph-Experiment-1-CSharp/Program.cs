using System;

namespace Chapter_4_Graph_Experiment_1_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("===== Matrix Graph Test =====");
            MatrixGraph matrixGraph = new MatrixGraph("matrix.txt");
            
            Console.WriteLine("BFS");
            matrixGraph.BFSTravel();
            Console.WriteLine(Environment.NewLine);
            
            Console.WriteLine("DFS");
            matrixGraph.DFSTravel();
            Console.WriteLine(Environment.NewLine);
            
            Console.WriteLine("DFS Recurse");
            matrixGraph.DFSTravel_Recurse();
            Console.WriteLine(Environment.NewLine);


            Console.WriteLine("===== List Graph Test =====");
            ListGraph listGraph = new ListGraph("list.txt");

            Console.WriteLine("BFS");
            listGraph.BFSTravel();
            Console.WriteLine(Environment.NewLine);

            Console.WriteLine("DFS");
            listGraph.DFSTravel();
            Console.WriteLine(Environment.NewLine);

            Console.WriteLine("DFS Recurse");
            listGraph.DFSTravel_Recurse();
            Console.WriteLine(Environment.NewLine);
        }
    }
}