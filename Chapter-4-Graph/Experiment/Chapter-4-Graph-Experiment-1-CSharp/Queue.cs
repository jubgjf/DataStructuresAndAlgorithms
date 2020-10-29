namespace Chapter_4_Graph_Experiment_1_CSharp
{
    class Queue
    {
        /// <summary>
        /// 初始化用两个栈模拟队列
        /// </summary>
        public Queue()
        {
            _enqueueStack = new Stack();
            _dequeueStack = new Stack();
        }

        /// <summary>
        /// 入队栈
        /// </summary>
        private Stack _enqueueStack;

        /// <summary>
        /// 出队栈
        /// </summary>
        private Stack _dequeueStack;

        /// <summary>
        /// 判断队列是否为空
        /// </summary>
        /// <returns>返回队列是否为空</returns>
        public bool IsEmpty()
        {
            return _enqueueStack.IsEmpty() && _dequeueStack.IsEmpty();
        }

        /// <summary>
        /// 将数据入队
        /// </summary>
        /// <param name="data">入队数据</param>
        public void Enqueue(int data)
        {
            _enqueueStack.Push(data);
        }

        /// <summary>
        /// 出队
        /// </summary>
        /// <returns>返回出队数据</returns>
        public int Dequeue()
        {
            if (!_dequeueStack.IsEmpty()) { return _dequeueStack.Pop(); }

            while (!_enqueueStack.IsEmpty())
            {
                _dequeueStack.Push(_enqueueStack.Pop());
            }

            return _dequeueStack.Pop();
        }
    }
}
