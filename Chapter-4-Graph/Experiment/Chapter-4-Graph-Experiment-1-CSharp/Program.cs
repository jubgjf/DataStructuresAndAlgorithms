using System;

namespace Chapter_4_Graph_Experiment_1_CSharp
{
    static class Program
    {
        static void Main()
        {
            Console.WriteLine("===== Matrix Graph Test =====");
            MatrixGraph matrixGraph = new MatrixGraph("matrix.txt");
            matrixGraph.TestTravel();
            // int[][] list = matrixGraph.ConvertToListGraph();
            //
            // ListGraph l = new ListGraph(list);


            Console.WriteLine("===== List Graph Test =====");
            ListGraph listGraph = new ListGraph("list.txt");
            listGraph.TestTravel();
            // int[,] matrix = listGraph.ConvertToMatrixGraph();
            //
            // MatrixGraph m = new MatrixGraph(matrix);
        }
    }
}