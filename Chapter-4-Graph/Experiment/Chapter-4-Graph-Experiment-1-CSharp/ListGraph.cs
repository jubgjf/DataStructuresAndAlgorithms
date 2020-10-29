using System;

namespace Chapter_4_Graph_Experiment_1_CSharp
{
    class ListGraph
    {
        /// <summary>
        /// 初始化图的邻接表
        /// </summary>
        /// <param name="listFileName">邻接表数据来源文件路径</param>
        public ListGraph(string listFileName)
        {
            _list = FileIO.ReadListFromFile(listFileName);
            _nodeCount = FileIO.GetFileLinesCount(listFileName);
        }

        /// <summary>
        /// 图的邻接表
        /// </summary>
        private int[][] _list;

        /// <summary>
        /// 图的节点个数
        /// </summary>
        private int _nodeCount;

        /// <summary>
        /// 获取与指定节点相邻的节点的下标
        /// </summary>
        /// <param name="nodeIndex">指定节点的下标</param>
        /// <returns>返回所有相邻节点的下标</returns>
        private int[] GetAdjacent(int nodeIndex)
        {
            foreach (int[] nodes in _list)
            {
                if (nodes[0] == nodeIndex)
                {
                    return nodes[new Range(1, nodes.Length)];
                }
            }

            return null;
        }

        /// <summary>
        /// 深度优先搜索（非递归）
        /// </summary>
        public void DFSTravel()
        {
            Stack nodeStack = new Stack();
            bool[] traveled = new bool[_nodeCount];
            
            // TODO 遍历多个支
            int currentNodeIndex = 0;
            nodeStack.Push(currentNodeIndex);
            Console.Write(currentNodeIndex + "-");
            traveled[currentNodeIndex] = true;
            while (!nodeStack.IsEmpty())
            {
                bool findUntraveledAdjacent = false;
                // 在相邻节点中，查找未走过的节点
                foreach (int adjacent in GetAdjacent(currentNodeIndex))
                {
                    if (!traveled[adjacent])
                    {
                        findUntraveledAdjacent = true;
                        currentNodeIndex = adjacent;
                        nodeStack.Push(currentNodeIndex);
                        Console.Write(currentNodeIndex + "-");
                        traveled[currentNodeIndex] = true;
                        break;
                    }
                }
            
                // 没有未走过的相邻节点
                if (!findUntraveledAdjacent)
                {
                    nodeStack.Pop();
                    currentNodeIndex = nodeStack.Top();
                }
            }
            
            Console.Write("\b ");
        }

        /// <summary>
        /// 深度优先搜索（递归）
        /// </summary>
        public void DFSTravel_Recurse()
        {
            // TODO 无法区分有向图的弱连通和不在同一支
            
            bool[] traveled = new bool[_nodeCount];
            
            for (int i = 0; i < _nodeCount; i++)
            {
                if (!traveled[i])
                {
                    DFSTravelFromNode(i, ref traveled);
                    Console.WriteLine("\b ");
                }
            }
        }

        /// <summary>
        /// 从指定节点出发，深度优先遍历图
        /// </summary>
        /// <param name="nodeIndex">指定节点的下标</param>
        /// <param name="traveled">记录已走过的节点数组</param>
        private void DFSTravelFromNode(int nodeIndex, ref bool[] traveled)
        {
            Console.Write(nodeIndex + "-");
            traveled[nodeIndex] = true;
            
            int[] adjacentNodes = GetAdjacent(nodeIndex);
            foreach (int adjacentNode in adjacentNodes)
            {
                if (!traveled[adjacentNode])
                {
                    DFSTravelFromNode(adjacentNode, ref traveled);
                }
            }
        }

        /// <summary>
        /// 广度优先搜索
        /// </summary>
        public void BFSTravel()
        {
            bool[] traveled = new bool[_nodeCount];
            Queue nodeQueue = new Queue();
            
            // TODO 遍历多个支
            nodeQueue.Enqueue(0);
            traveled[0] = true;
            while (!nodeQueue.IsEmpty())
            {
                int currentNodeIndex = nodeQueue.Dequeue();
                Console.Write(currentNodeIndex + "-");
                traveled[currentNodeIndex] = true;
                foreach (int adjacent in GetAdjacent(currentNodeIndex))
                {
                    if (!traveled[adjacent])
                    {
                        nodeQueue.Enqueue(adjacent);
                    }
                }
            }
            Console.Write("\b ");
        }
    }
}
