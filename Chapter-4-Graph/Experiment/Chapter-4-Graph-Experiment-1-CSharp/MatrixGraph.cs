namespace Chapter_4_Graph_Experiment_1_CSharp
{
    class MatrixGraph : Graph
    {
        /// <summary>
        /// 初始化图的邻接矩阵和节点数
        /// </summary>
        /// <param name="matrixFileName">邻接矩阵数据来源文件路径</param>
        public MatrixGraph(string matrixFileName)
        {
            NodeCount = FileIO.GetMatrixWidthFromFile(matrixFileName);
            Matrix = FileIO.ReadMatrixFromFile(matrixFileName);
        }

        /// <summary>
        /// 图的邻接矩阵
        /// </summary>
        private int[,] Matrix { get; set; }

        protected override int[] GetAdjacent(int nodeIndex)
        {
            int neighborCount = 0;

            for (int i = 0; i < NodeCount; i++)
            {
                if (Matrix[nodeIndex, i] != 0) { neighborCount++; }
            }

            int[] neighbors = new int[neighborCount];

            for (int i = 0, j = 0; i < NodeCount && j < neighborCount; i++)
            {
                if (Matrix[nodeIndex, i] != 0)
                {
                    neighbors[j] = i;
                    j++;
                }
            }

            return neighbors;
        }
    }
}