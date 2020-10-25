using System;

namespace Chapter_3_Tree_Homework_1_CSharp
{
    class Heap
    {
        public Heap()
        {
            _lastIndex = 0;
        }

        /// <summary>
        /// 堆最大空间
        /// </summary>
        private const int MaxHeapSize = 128;

        /// <summary>
        /// 堆中元素保存的数据
        /// </summary>
        public struct CharData
        {
            public char Char;
            public int Weight;
            public int Index;
        }

        /// <summary>
        /// 堆的数据
        /// </summary>
        private CharData[] _heapData = new CharData[MaxHeapSize];

        /// <summary>
        /// 堆数据数组的最有一个元素下标
        /// </summary>
        private int _lastIndex;

        /// <summary>
        /// 交换堆的两个元素
        /// </summary>
        /// <param name="charData1">第一个元素</param>
        /// <param name="charData2">第二个元素</param>
        private void Swap(ref CharData charData1, ref CharData charData2)
        {
            CharData tempCharData = charData1;
            charData1 = charData2;
            charData2 = tempCharData;
        }

        /// <summary>
        /// 获取两个孩子节点中，权值最小的孩子节点在栈中的下标
        /// </summary>
        /// <param name="parentIndex">父节点下标</param>
        /// <returns>返回孩子节点下标</returns>
        private int MinChildIndex(int parentIndex)
        {
            if (parentIndex * 2 + 1 <= _lastIndex)
            {
                return _heapData[parentIndex * 2].Weight < _heapData[parentIndex * 2 + 1].Weight
                    ? parentIndex * 2
                    : parentIndex * 2 + 1;
            }
            else if (parentIndex * 2 <= _lastIndex)
            {
                return parentIndex * 2;
            }
            else
            {
                return -1;
            }
        }

        /// <summary>
        /// 向堆中插入新元素，并更新小顶堆
        /// </summary>
        /// <param name="charData">待插入的元素</param>
        public void Insert(CharData charData)
        {
            // 在尾部插入新元素
            _heapData[_lastIndex + 1] = charData;
            _lastIndex++;
            int newElementIndex = _lastIndex;

            // 更新堆
            if (newElementIndex == 1)
            {
                return;
            }

            while (Convert.ToInt32(newElementIndex / 2) != 0 &&
                   _heapData[Convert.ToInt32(newElementIndex / 2)].Weight > charData.Weight)
            {
                Swap(ref _heapData[Convert.ToInt32(newElementIndex / 2)], ref _heapData[newElementIndex]);
                newElementIndex = Convert.ToInt32(newElementIndex / 2);
            }
        }

        /// <summary>
        /// 删除堆顶元素，并更新小顶堆
        /// </summary>
        /// <returns>返回原堆顶元素</returns>
        public CharData Pop()
        {
            // 交换根和最后一个元素
            CharData originTop = _heapData[1];
            Swap(ref _heapData[1], ref _heapData[_lastIndex]);
            _heapData[_lastIndex].Weight = 0;
            _lastIndex--;
            int currentElementIndex = 1;

            // 更新堆
            while (true)
            {
                int minChildIndex = MinChildIndex(currentElementIndex);
                if (minChildIndex != -1 &&
                    _heapData[currentElementIndex].Weight > _heapData[minChildIndex].Weight)
                {
                    Swap(ref _heapData[currentElementIndex], ref _heapData[minChildIndex]);
                    currentElementIndex = minChildIndex;
                }
                else
                {
                    break;
                }
            }

            return originTop;
        }

        /// <summary>
        /// 查询堆顶元素
        /// </summary>
        /// <returns>返回堆顶元素</returns>
        public CharData Top()
        {
            return _heapData[1];
        }

        /// <summary>
        /// 查询堆是否为空
        /// </summary>
        /// <returns>返回堆为空的结果</returns>
        public bool IsEmpty()
        {
            return _lastIndex == 0;
        }
    }
}