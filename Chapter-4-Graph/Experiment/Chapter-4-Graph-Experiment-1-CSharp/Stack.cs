namespace Chapter_4_Graph_Experiment_1_CSharp
{
    class Stack
    {
        /// <summary>
        /// 初始化栈
        /// </summary>
        public Stack()
        {
            _topIndex = -1;
            _storePool = new int[MaxSize];
        }

        /// <summary>
        /// 栈的存储池最大空间
        /// </summary>
        private const int MaxSize = 100;

        /// <summary>
        /// 栈的存储池
        /// </summary>
        private int[] _storePool;

        /// <summary>
        /// 栈顶元素在存储池的下标
        /// </summary>
        private int _topIndex;

        /// <summary>
        /// 判断栈是否为空
        /// </summary>
        /// <returns></returns>
        public bool IsEmpty()
        {
            return _topIndex < 0;
        }

        /// <summary>
        /// 将数据压栈
        /// </summary>
        /// <param name="data">待压栈的数据</param>
        public void Push(int data)
        {
            if (_topIndex >= MaxSize - 1) { return; }

            _storePool[_topIndex + 1] = data;
            _topIndex++;
        }

        /// <summary>
        /// 弹栈
        /// </summary>
        /// <returns>返回弹出的数据</returns>
        public int Pop()
        {
            if (IsEmpty()) { return -1; }

            int popData = Top();
            _topIndex--;

            return popData;
        }

        /// <summary>
        /// 查看栈顶元素数据
        /// </summary>
        /// <returns>返回栈顶元素数据</returns>
        public int Top()
        {
            if (IsEmpty()) { return -1; }

            return _storePool[_topIndex];
        }
    }
}
