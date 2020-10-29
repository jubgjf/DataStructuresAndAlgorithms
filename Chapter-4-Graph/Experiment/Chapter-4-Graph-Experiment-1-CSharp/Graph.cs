using System;

namespace Chapter_4_Graph_Experiment_1_CSharp
{
    abstract class Graph
    {
        /// <summary>
        /// 图的节点个数
        /// </summary>
        protected int NodeCount;

        /// <summary>
        /// 获取与指定节点相邻的节点的下标
        /// </summary>
        /// <param name="nodeIndex">指定节点的下标</param>
        /// <returns>返回所有相邻节点的下标</returns>
        protected abstract int[] GetAdjacent(int nodeIndex);

        /// <summary>
        /// 深度优先搜索（非递归）
        /// </summary>
        private void DFSTravel()
        {
            Stack nodeStack = new Stack();
            bool[] traveled = new bool[NodeCount];

            for (int i = 0; i < NodeCount; i++)
            {
                if (!traveled[i])
                {
                    int currentNodeIndex = i;
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

                    Console.Write("\b " + Environment.NewLine);
                }
            }
        }

        /// <summary>
        /// 深度优先搜索（递归）
        /// </summary>
        private void DFSTravel_Recurse()
        {
            // TODO 无法区分有向图的弱连通和不在同一支

            bool[] traveled = new bool[NodeCount];

            for (int i = 0; i < NodeCount; i++)
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
        private void BFSTravel()
        {
            bool[] traveled = new bool[NodeCount];
            Queue nodeQueue = new Queue();

            for (int i = 0; i < NodeCount; i++)
            {
                if (!traveled[i])
                {
                    nodeQueue.Enqueue(i);
                    traveled[i] = true;
                    while (!nodeQueue.IsEmpty())
                    {
                        int currentNodeIndex = nodeQueue.Dequeue();
                        Console.Write(currentNodeIndex + "-");
                        foreach (int adjacent in GetAdjacent(currentNodeIndex))
                        {
                            if (!traveled[adjacent])
                            {
                                nodeQueue.Enqueue(adjacent);
                                traveled[adjacent] = true;
                            }
                        }
                    }

                    Console.Write("\b " + Environment.NewLine);
                }
            }
        }

        /// <summary>
        /// 测试图的遍历
        /// </summary>
        public void TestTravel()
        {
            Console.WriteLine("BFS");
            BFSTravel();
            Console.WriteLine(Environment.NewLine);

            Console.WriteLine("DFS");
            DFSTravel();
            Console.WriteLine(Environment.NewLine);

            Console.WriteLine("DFS Recurse");
            DFSTravel_Recurse();
            Console.WriteLine(Environment.NewLine);
        }
    }
}