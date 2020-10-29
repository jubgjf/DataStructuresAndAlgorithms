using System;

namespace Chapter_4_Graph_Experiment_1_CSharp
{
    class ListGraph : Graph
    {
        /// <summary>
        /// 初始化图的邻接表
        /// </summary>
        /// <param name="listFileName">邻接表数据来源文件路径</param>
        public ListGraph(string listFileName)
        {
            NodeCount = FileIO.GetFileLinesCount(listFileName);
            List = FileIO.ReadListFromFile(listFileName);
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
    }
}