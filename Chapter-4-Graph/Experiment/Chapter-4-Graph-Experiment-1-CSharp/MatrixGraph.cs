namespace Chapter_4_Graph_Experiment_1_CSharp
{
    class MatrixGraph
    {
        /// <summary>
        /// 初始化图的邻接矩阵和节点数
        /// </summary>
        /// <param name="matrixFileName"></param>
        public MatrixGraph(string matrixFileName)
        {
            _nodeCount = FileIO.GetMatrixWidthFromFile(matrixFileName);
            _matrix = FileIO.ReadMatrixFromFile(matrixFileName);
        }

        /// <summary>
        /// 图的节点数，邻接矩阵实际长度
        /// </summary>
        private int _nodeCount;

        /// <summary>
        /// 图的邻接矩阵
        /// </summary>
        private int[,] _matrix;

        /// <summary>
        /// 获取与指定节点相邻的节点的下标
        /// </summary>
        /// <param name="nodeIndex">指定节点的下标</param>
        /// <returns>返回所有相邻节点的下标</returns>
        private int[] GetAdjacent(int nodeIndex)
        {
            int neighborCount = 0;

            for (int i = 0; i < _nodeCount; i++)
            {
                if (_matrix[nodeIndex, i] != 0) { neighborCount++; }
            }

            int[] neighbors = new int[neighborCount];

            for (int i = 0; i < neighborCount; i++)
            {
                for (int j = 0; j < _nodeCount; j++)
                {
                    if (_matrix[nodeIndex, j] != 0) { neighbors[i] = j; }
                }
            }

            return neighbors;
        }

        /// <summary>
        /// 深度优先搜索（非递归）
        /// </summary>
        public void DFSTravel()
        {
        }

        /// <summary>
        /// 深度优先搜索（递归）
        /// </summary>
        public void DFSTravel_Recurse()
        {
        }

        /// <summary>
        /// 广度优先搜索
        /// </summary>
        public void BFSTravel()
        {
        }
    }
}