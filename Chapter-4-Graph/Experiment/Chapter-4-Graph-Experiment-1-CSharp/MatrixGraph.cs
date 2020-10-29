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
        /// 初始化图的邻接矩阵和节点数
        /// </summary>
        /// <param name="matrix">图的邻接矩阵</param>
        public MatrixGraph(int[,] matrix)
        {
            NodeCount = matrix.GetLength(0);
            Matrix = matrix;
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

        /// <summary>
        /// 将用邻接矩阵表示的图，转换为用邻接表表示的图
        /// </summary>
        /// <returns>返回邻接表</returns>
        public int[][] ConvertToListGraph()
        {
            int[][] list = new int[NodeCount][];

            for (int i = 0; i < NodeCount; i++)
            {
                // 记录与节点i邻接的节点数量
                int adjacentCount = 0;
                for (int j = 0; j < NodeCount; j++)
                {
                    if (Matrix[i, j] != 0) { adjacentCount++; }
                }

                int[] adjacent = new int[adjacentCount + 1];
                adjacent[0] = i;
                int adjacentIndex = 1;
                for (int j = 0; j < NodeCount && adjacentIndex < adjacentCount; j++)
                {
                    // 节点i到节点j有弧
                    if (Matrix[i, j] != 0)
                    {
                        adjacent[adjacentIndex] = j;
                    }
                }

                list[i] = adjacent;
            }

            return list;
        }
    }
}