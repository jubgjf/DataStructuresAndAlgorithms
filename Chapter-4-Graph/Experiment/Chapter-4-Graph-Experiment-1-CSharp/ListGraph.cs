using System;

namespace Chapter_4_Graph_Experiment_1_CSharp
{
    class ListGraph : Graph
    {
        /// <summary>
        /// 初始化图的邻接表和节点数
        /// </summary>
        /// <param name="listFileName">邻接表数据来源文件路径</param>
        public ListGraph(string listFileName)
        {
            NodeCount = FileIO.GetFileLinesCount(listFileName);
            List = FileIO.ReadListFromFile(listFileName);
        }

        /// <summary>
        /// 初始化图的邻接表和节点数
        /// </summary>
        /// <param name="list">邻接表</param>
        public ListGraph(int[][] list)
        {
            NodeCount = list.GetLength(0);
            List = list;
        }

        /// <summary>
        /// 图的邻接表
        /// </summary>
        private int[][] List { get; set; }

        protected override int[] GetAdjacent(int nodeIndex)
        {
            foreach (int[] nodes in List)
            {
                if (nodes[0] == nodeIndex)
                {
                    return nodes[new Range(1, nodes.Length)];
                }
            }

            return null;
        }

        /// <summary>
        /// 将用邻接表表示的图，转换为用邻接矩阵表示的图
        /// </summary>
        /// <returns>返回邻接矩阵</returns>
        public int[,] ConvertToMatrixGraph()
        {
            int[,] matrix = new int[NodeCount, NodeCount];

            foreach (int[] nodes in List)
            {
                for (int i = 1; i < nodes.Length; i++)
                {
                    matrix[nodes[0], nodes[i]] = 1;
                }
            }

            return matrix;
        }
    }
}