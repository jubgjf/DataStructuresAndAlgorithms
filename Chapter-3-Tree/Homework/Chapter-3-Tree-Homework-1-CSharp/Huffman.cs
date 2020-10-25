using System;

namespace Chapter_3_Tree_Homework_1_CSharp
{
    class Huffman
    {
        /// <summary>
        /// 初始化没有结构的哈夫曼树
        /// </summary>
        /// <param name="charData">字符分析结果数组，字符的ASCII码是数组下标位置</param>
        public Huffman(int[] charData)
        {
            // 空哈夫曼树
            int leafCount = File.CountValidChar(charData);
            HuffmanTree = new HuffmanTreeNode[2 * leafCount - 1];

            // 填充叶节点
            int huffmanTreeIndex = 0;
            for (int i = 0; huffmanTreeIndex < leafCount; i++)
            {
                if (charData[i] > 0)
                {
                    HuffmanTree[huffmanTreeIndex] = new HuffmanTreeNode
                    {
                        Char = Convert.ToChar(i),
                        Weight = charData[i],
                        LeftChildIndex = -1,
                        RightChildIndex = -1,
                        ParentIndex = -1
                    };
                    huffmanTreeIndex++;
                }
            }
        }

        /// <summary>
        /// 哈夫曼树节点
        /// </summary>
        public struct HuffmanTreeNode
        {
            public char Char;
            public int Weight;
            public int ParentIndex;
            public int LeftChildIndex;
            public int RightChildIndex;
        }

        /// <summary>
        /// 哈夫曼树
        /// </summary>
        public HuffmanTreeNode[] HuffmanTree;
    }
}