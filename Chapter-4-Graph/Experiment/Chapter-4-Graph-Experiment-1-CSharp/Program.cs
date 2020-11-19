using System;

namespace Chapter_4_Graph_Experiment_1_CSharp
{
    static class Program
    {
        static void Main()
        {
            Console.WriteLine("===== Matrix Graph Test =====" + Environment.NewLine);

            Console.WriteLine("=== Matrix ===");
            MatrixGraph matrixGraph = new MatrixGraph("matrix.txt");
            matrixGraph.TestTravel();

            Console.WriteLine("=== Matrix To List ===");
            int[][] list = matrixGraph.ConvertToListGraph();
            ListGraph l = new ListGraph(list);
            l.TestTravel();


            Console.WriteLine("===== List Graph Test =====" + Environment.NewLine);

            Console.WriteLine("=== List ===");
            ListGraph listGraph = new ListGraph("list.txt");
            listGraph.TestTravel();

            Console.WriteLine("=== List To Matrix ===");
            int[,] matrix = listGraph.ConvertToMatrixGraph();
            MatrixGraph m = new MatrixGraph(matrix);
            m.TestTravel();
        }
    }
}