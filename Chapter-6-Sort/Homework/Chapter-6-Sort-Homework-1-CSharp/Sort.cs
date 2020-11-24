namespace Chapter_6_Sort_Homework_1_CSharp
{
    public static class Sort
    {
        /// <summary>
        /// 交换两个数
        /// </summary>
        /// <param name="a">第一个数</param>
        /// <param name="b">第二个数</param>
        private static void Swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        /// <summary>
        /// 冒泡排序
        /// </summary>
        /// <param name="array">数组</param>
        public static void BubbleSort(ref int[] array)
        {
            for (int i = 0; i < array.Length; ++i)
            {
                bool exchanged = false;

                for (int j = array.Length - 1; j > i; --j)
                {
                    if (array[j - 1] > array[j])
                    {
                        Swap(ref array[j - 1], ref array[j]);
                        exchanged = true;
                    }
                }

                if (!exchanged)
                {
                    break;
                }
            }
        }

        /// <summary>
        /// 快速排序
        /// </summary>
        /// <param name="array">数组</param>
        /// <param name="startIndex">开始排序下标</param>
        /// <param name="endIndex">结束排序下标</param>
        public static void QuickSort(ref int[] array, int startIndex, int endIndex)
        {
            if (startIndex > endIndex)
            {
                return;
            }

            int pivot = array[startIndex];
            int i = startIndex, j = endIndex;

            while (i != j)
            {
                while (array[j] >= pivot && j > i)
                {
                    --j;
                }

                while (array[i] <= pivot && i < j)
                {
                    ++i;
                }

                if (i < j)
                {
                    Swap(ref array[i], ref array[j]);
                }
            }

            array[startIndex] = array[i];
            array[i] = pivot;

            QuickSort(ref array, i + 1, endIndex);
            QuickSort(ref array, startIndex, i - 1);
        }

        /// <summary>
        /// 选择排序
        /// </summary>
        /// <param name="array">数组</param>
        public static void SelectSort(ref int[] array)
        {
            for (int i = 0; i < array.Length - 1; ++i)
            {
                int minIndex = i;

                for (int j = i; j < array.Length; ++j)
                {
                    if (array[j] < array[minIndex])
                    {
                        minIndex = j;
                    }
                }

                Swap(ref array[i], ref array[minIndex]);
            }
        }

        /// <summary>
        /// 获取左孩子下标
        /// </summary>
        /// <param name="index">当前下标</param>
        /// <param name="lastIndex">堆的最后一个元素的下标</param>
        /// <returns>获取左孩子下标，没有左孩子则返回-1</returns>
        private static int LeftChildIndex(int index, int lastIndex)
        {
            return index * 2 > lastIndex ? -1 : index * 2;
        }

        /// <summary>
        /// 获取右孩子下标
        /// </summary>
        /// <param name="index">当前下标</param>
        /// <param name="lastIndex">堆的最后一个元素的下标</param>
        /// <returns>获取右孩子下标，没有右孩子则返回-1</returns>
        private static int RightChildIndex(int index, int lastIndex)
        {
            return index * 2 + 1 > lastIndex ? -1 : index * 2 + 1;
        }

        /// <summary>
        /// 向小顶堆中插入元素
        /// </summary>
        /// <param name="heap">小顶堆</param>
        /// <param name="lastIndex">堆数组的最后一个元素的下标</param>
        /// <param name="insertData">待插入的元素</param>
        private static void HeapInsert(ref int[] heap, ref int lastIndex, int insertData)
        {
            heap[lastIndex + 1] = insertData;
            lastIndex++;
            int currentIndex = lastIndex;

            while (heap[currentIndex] < heap[currentIndex / 2] && currentIndex != 1)
            {
                Swap(ref heap[currentIndex], ref heap[currentIndex / 2]);
                currentIndex /= 2;
            }
        }

        /// <summary>
        /// 从小顶堆中弹出根
        /// </summary>
        /// <param name="heap">小顶堆</param>
        /// <param name="lastIndex">堆数组的最后一个元素的下标</param>
        /// <returns>弹出的元素</returns>
        private static int HeapPop(ref int[] heap, ref int lastIndex)
        {
            Swap(ref heap[1], ref heap[lastIndex]);
            lastIndex--;

            int currentIndex = 1;
            while (true)
            {
                if (LeftChildIndex(currentIndex, lastIndex) == -1) // 没有左孩子
                {
                    break;
                }
                else if (RightChildIndex(currentIndex, lastIndex) == -1) // 有左孩子，没有右孩子
                {
                    if (heap[currentIndex] > heap[LeftChildIndex(currentIndex, lastIndex)])
                    {
                        Swap(ref heap[currentIndex], ref heap[LeftChildIndex(currentIndex, lastIndex)]);
                        currentIndex = currentIndex * 2;
                    }
                    else
                    {
                        break;
                    }
                }
                else // 有左孩子、右孩子
                {
                    if (heap[currentIndex] < heap[LeftChildIndex(currentIndex, lastIndex)] &&
                        heap[currentIndex] < heap[RightChildIndex(currentIndex, lastIndex)])
                    {
                        break;
                    }
                    else if (heap[LeftChildIndex(currentIndex, lastIndex)] <
                             heap[RightChildIndex(currentIndex, lastIndex)])
                    {
                        Swap(ref heap[currentIndex], ref heap[LeftChildIndex(currentIndex, lastIndex)]);
                        currentIndex = currentIndex * 2;
                    }
                    else if (heap[LeftChildIndex(currentIndex, lastIndex)] >=
                             heap[RightChildIndex(currentIndex, lastIndex)])
                    {
                        Swap(ref heap[currentIndex], ref heap[RightChildIndex(currentIndex, lastIndex)]);
                        currentIndex = currentIndex * 2 + 1;
                    }
                }
            }

            return heap[lastIndex + 1];
        }

        /// <summary>
        /// 堆排序
        /// </summary>
        /// <param name="array">数组</param>
        public static void HeapSort(ref int[] array)
        {
            // 构建小顶堆
            int[] heap = new int[10000];
            int heapLastIndex = 0;
            foreach (int i in array)
            {
                HeapInsert(ref heap, ref heapLastIndex, i);
            }

            for (int i = 0; heapLastIndex >= 1; ++i)
            {
                array[i] = HeapPop(ref heap, ref heapLastIndex);
            }
        }

        /// <summary>
        /// 插入排序
        /// </summary>
        /// <param name="array">数组</param>
        public static void InsertSort(ref int[] array)
        {
            for (int i = 1; i < array.Length; ++i)
            {
                for (int j = i; j - 1 >= 0 && array[j] < array[j - 1]; --j)
                {
                    Swap(ref array[j], ref array[j - 1]);
                }
            }
        }

        /// <summary>
        /// 希尔排序
        /// </summary>
        /// <param name="array">数组</param>
        public static void ShellSort(ref int[] array)
        {
            for (int gap = array.Length / 2; gap > 0; gap /= 2)
            {
                for (int i = gap; i < array.Length; ++i)
                {
                    for (int j = i; j - gap >= 0 && array[j] < array[j - gap]; j -= gap)
                    {
                        Swap(ref array[j], ref array[j - gap]);
                    }
                }
            }
        }
    }
}