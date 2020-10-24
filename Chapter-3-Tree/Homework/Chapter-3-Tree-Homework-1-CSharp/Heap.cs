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
            public int Frequency;
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
        /// 向堆中插入新元素，并更新大顶堆
        /// </summary>
        /// <param name="charData">待插入的元素</param>
        public void Insert(CharData charData)
        {
            // 在尾部插入新元素
            _heapData[_lastIndex + 1] = charData;
            _lastIndex++;
            int newElementIndex = _lastIndex;

            // 更新堆
            if (newElementIndex == 1) { return; }
            while (Convert.ToInt32(newElementIndex / 2) != 0 &&
                   _heapData[Convert.ToInt32(newElementIndex / 2)].Frequency < charData.Frequency)
            {
                Swap(ref _heapData[Convert.ToInt32(newElementIndex / 2)], ref _heapData[newElementIndex]);
                newElementIndex = Convert.ToInt32(newElementIndex / 2);
            }
        }

        /// <summary>
        /// 删除堆顶元素，并更新大顶堆
        /// </summary>
        /// <returns>返回原堆顶元素</returns>
        public CharData Pop()
        {
            // 交换根和最后一个元素
            Swap(ref _heapData[1], ref _heapData[_lastIndex]);
            _lastIndex--;
            int currentElementIndex = 1;

            // 更新堆
            while (true)
            {
                if (_heapData[currentElementIndex].Frequency < _heapData[currentElementIndex * 2].Frequency)
                {
                    Swap(ref _heapData[currentElementIndex], ref _heapData[currentElementIndex * 2]);
                    currentElementIndex = currentElementIndex * 2;
                }
                else if (_heapData[currentElementIndex].Frequency < _heapData[currentElementIndex * 2 + 1].Frequency)
                {
                    Swap(ref _heapData[currentElementIndex], ref _heapData[currentElementIndex * 2 + 1]);
                    currentElementIndex = currentElementIndex * 2 + 1;
                }
                else
                {
                    break;
                }
            }

            return _heapData[_lastIndex + 1];
        }

        /// <summary>
        /// 查询堆顶元素
        /// </summary>
        /// <returns>返回堆顶元素</returns>
        public CharData Top()
        {
            return _heapData[1];
        }
    }
}