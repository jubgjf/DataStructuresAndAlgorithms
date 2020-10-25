using System;
using System.Collections;

namespace Chapter_3_Tree_Homework_1_CSharp
{
    class Huffman
    {
        /// <summary>
        /// 初始化哈夫曼树和哈夫曼编码表
        /// </summary>
        /// <param name="charData">字符分析结果数组，字符的ASCII码是数组下标位置</param>
        public Huffman(int[] charData)
        {
            // 初始化叶节点
            int leafCount = File.CountValidChar(charData);
            Heap heap = InitLeafNode(charData, leafCount);

            // 生成哈夫曼树结构
            GenHuffmanTreeStructure(heap);

            // 生成哈夫曼编码表
            GenHuffmanCodeMap(leafCount);
        }

        /// <summary>
        /// 哈夫曼树节点
        /// </summary>
        private struct HuffmanTreeNode
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
        private HuffmanTreeNode[] _huffmanTree;

        /// <summary>
        /// 哈夫曼树最后一个元素的下标
        /// </summary>
        private int _huffmanTreeLastIndex;

        /// <summary>
        /// 一个字符的哈夫曼编码
        /// </summary>
        public struct HuffmanCodeMapElement
        {
            public char Char;
            public BitArray Code;
        }

        /// <summary>
        /// 哈夫曼编码表
        /// </summary>
        public HuffmanCodeMapElement[] HuffmanCodeMap;

        /// <summary>
        /// 初始化哈夫曼树叶节点，并生成叶节点小顶堆
        /// </summary>
        /// <param name="charData">字符分析结果数组</param>
        /// <param name="leafCount">叶节点个数</param>
        /// <returns>返回小顶堆</returns>
        private Heap InitLeafNode(int[] charData, int leafCount)
        {
            _huffmanTree = new HuffmanTreeNode[2 * leafCount - 1];
            Heap heap = new Heap();
            int huffmanTreeIndex = 0;

            for (int i = 0; huffmanTreeIndex < leafCount; i++)
            {
                if (charData[i] > 0)
                {
                    // 填充哈夫曼树
                    _huffmanTree[huffmanTreeIndex] = new HuffmanTreeNode
                    {
                        Char = Convert.ToChar(i),
                        Weight = charData[i],
                        LeftChildIndex = -1,
                        RightChildIndex = -1,
                        ParentIndex = -1
                    };

                    // 填充小顶堆
                    heap.Insert(new Heap.CharData
                    {
                        Char = _huffmanTree[huffmanTreeIndex].Char,
                        Index = huffmanTreeIndex,
                        Weight = _huffmanTree[huffmanTreeIndex].Weight
                    });

                    huffmanTreeIndex++;
                }
            }

            _huffmanTreeLastIndex = huffmanTreeIndex - 1;
            return heap;
        }

        /// <summary>
        /// 生成哈夫曼树结构
        /// </summary>
        /// <param name="heap">叶节点小顶堆</param>
        private void GenHuffmanTreeStructure(Heap heap)
        {
            // 初始两个叶节点建立结构
            Heap.CharData firstLeaf = heap.Pop();
            Heap.CharData secondLeaf = heap.Pop();
            _huffmanTree[_huffmanTreeLastIndex + 1].LeftChildIndex = firstLeaf.Index;
            _huffmanTree[_huffmanTreeLastIndex + 1].RightChildIndex = secondLeaf.Index;
            _huffmanTree[_huffmanTreeLastIndex + 1].Weight = firstLeaf.Weight + secondLeaf.Weight;
            _huffmanTree[firstLeaf.Index].ParentIndex = _huffmanTreeLastIndex + 1;
            _huffmanTree[secondLeaf.Index].ParentIndex = _huffmanTreeLastIndex + 1;
            _huffmanTreeLastIndex++;

            // 建立其余结构
            while (!heap.IsEmpty())
            {
                Heap.CharData leaf = heap.Pop();
                _huffmanTree[_huffmanTreeLastIndex + 1].LeftChildIndex = leaf.Index;
                _huffmanTree[_huffmanTreeLastIndex + 1].RightChildIndex = _huffmanTreeLastIndex;
                _huffmanTree[_huffmanTreeLastIndex + 1].Weight =
                    leaf.Weight + _huffmanTree[_huffmanTreeLastIndex].Weight;
                _huffmanTree[leaf.Index].ParentIndex = _huffmanTreeLastIndex + 1;
                _huffmanTree[_huffmanTreeLastIndex].ParentIndex = _huffmanTreeLastIndex + 1;
                _huffmanTreeLastIndex++;
            }

            _huffmanTree[_huffmanTreeLastIndex].ParentIndex = -1;
        }

        /// <summary>
        /// 生成一个指定字符的哈夫曼编码
        /// </summary>
        /// <param name="index">字符在哈夫曼树中的下标</param>
        /// <returns>返回字符的哈夫曼编码</returns>
        private BitArray GenCharCode(int index)
        {
            BitArray charCode = new BitArray(0);

            while (_huffmanTree[index].ParentIndex != -1)
            {
                int parentIndex = _huffmanTree[index].ParentIndex;

                BitArray newCharCode = new BitArray(charCode.Length + 1);
                for (int i = 0; i < charCode.Length; i++)
                {
                    newCharCode[i + 1] = charCode[i];
                }

                newCharCode[0] = _huffmanTree[parentIndex].LeftChildIndex != index;
                charCode = newCharCode;

                index = parentIndex;
            }

            return charCode;
        }

        /// <summary>
        /// 生成哈夫曼编码表
        /// </summary>
        /// <param name="charVariety">字符种类数</param>
        private void GenHuffmanCodeMap(int charVariety)
        {
            HuffmanCodeMap = new HuffmanCodeMapElement[charVariety];
            for (int i = 0; i < charVariety; i++)
            {
                HuffmanCodeMap[i].Char = _huffmanTree[i].Char;
                HuffmanCodeMap[i].Code = GenCharCode(i);
            }
        }

        /// <summary>
        /// 将字符串转换为哈夫曼编码
        /// </summary>
        /// <param name="text">待转换字符串</param>
        /// <returns>返回字符串对应的哈夫曼编码</returns>
        public BitArray StringToHuffmanCode(string text)
        {
            BitArray huffmanCode = new BitArray(0);

            foreach (char c in text)
            {
                foreach (HuffmanCodeMapElement element in HuffmanCodeMap)
                {
                    if (element.Char == c)
                    {
                        BitArray newHuffmanCode = new BitArray(huffmanCode.Length + element.Code.Length);

                        for (int i = 0; i < huffmanCode.Length; i++)
                        {
                            newHuffmanCode[i] = huffmanCode[i];
                        }
                        for (int i = huffmanCode.Length; i < huffmanCode.Length+ element.Code.Length; i++)
                        {
                            newHuffmanCode[i] = element.Code[i - huffmanCode.Length];
                        }

                        huffmanCode = newHuffmanCode;
                        break;
                    }
                }
            }

            return huffmanCode;
        }

        /// <summary>
        /// 将一组哈夫曼编码还原回字符串
        /// </summary>
        /// <param name="huffmanCode">哈夫曼编码</param>
        /// <returns>还原的字符串</returns>
        public string HuffmanCodeToString(BitArray huffmanCode)
        {
            string resultString = "";
            int currentIndex = _huffmanTreeLastIndex;

            foreach (bool bit in huffmanCode)
            {
                currentIndex = bit == false
                    ? _huffmanTree[currentIndex].LeftChildIndex
                    : _huffmanTree[currentIndex].RightChildIndex;
                if (_huffmanTree[currentIndex].LeftChildIndex == -1 && _huffmanTree[currentIndex].RightChildIndex == -1)
                {
                    resultString += _huffmanTree[currentIndex].Char;
                    currentIndex = _huffmanTreeLastIndex;
                }
            }

            return resultString;
        }
    }
}