using System;

namespace Chapter_2_LinearList_Homework_2_CSharp
{
    /// <summary>
    /// 链表中的节点类
    /// </summary>
    class Node
    {
        public Node(string name = null, string brand = null, double price = 0, int count = 0)
        {
            Name = name;
            Brand = brand;
            Price = price;
            Count = count;

            Next = null;
        }

        public string Name;
        public string Brand;
        public double Price;
        public int Count;

        public Node Next;
    }

    /// <summary>
    /// 链表类
    /// </summary>
    class LinearList
    {
        /// <summary>
        /// 创建头节点
        /// </summary>
        public LinearList()
        {
            Head = new Node();
        }

        /// <summary>
        /// 头节点
        /// </summary>
        public Node Head;

        /// <summary>
        /// 向链表指定节点的后边插入新节点
        /// </summary>
        /// <param name="insertPosition">插入节点的位置</param>
        /// <param name="name">商品名</param>
        /// <param name="brand">商品名称</param>
        /// <param name="price">商品单价</param>
        /// <param name="count">商品数量</param>
        public void Insert(Node insertPosition, string name, string brand, double price, int count)
        {
            Node newNode = new Node(name, brand, price, count) {Next = insertPosition.Next};
            insertPosition.Next = newNode;
        }

        /// <summary>
        /// 按照价格升序，向链表中插入新节点
        /// </summary>
        /// <param name="list">待插入节点的链表</param>
        /// <param name="name">商品名</param>
        /// <param name="brand">商品名称</param>
        /// <param name="price">商品单价</param>
        /// <param name="count">商品数量</param>
        public void InsertByPrice(LinearList list, string name, string brand, double price, int count)
        {
            Node node = list.Head;

            while (node.Next != null && price > node.Next.Price)
            {
                node = node.Next;
            }

            if (node.Next == null)
            {
                Insert(node, name, brand, price, count);
                return;
            }

            Insert(node, name, brand, price, count);
        }

        /// <summary>
        /// 删除链表指定节点后边的节点
        /// </summary>
        /// <param name="deletePosition">删除节点的位置</param>
        public void Delete(Node deletePosition)
        {
            if (deletePosition.Next == null)
            {
                return;
            }

            Node tempNode = deletePosition.Next;
            deletePosition.Next = tempNode.Next;
        }

        /// <summary>
        /// 更新链表指定节点的数据
        /// </summary>
        /// <param name="updatePosition">待更新数据的节点</param>
        /// <param name="name">新商品名</param>
        /// <param name="brand">新商品名称</param>
        /// <param name="price">新商品单价</param>
        /// <param name="count">新商品数量</param>
        public void Update(Node updatePosition, string name, string brand, double price, int count)
        {
            updatePosition.Name = name;
            updatePosition.Brand = brand;
            updatePosition.Price = price;
            updatePosition.Count = count;
        }

        /// <summary>
        /// 对链表数据进行搜索的方式
        /// </summary>
        public enum SearchType
        {
            SearchName,
            SearchBrand,
            SearchPrice,
            SearchCount,
        }

        /// <summary>
        /// 搜索链表中的数据
        /// </summary>
        /// <param name="list">待搜索的链表</param>
        /// <param name="objectToSearch">待搜索的数据</param>
        /// <param name="searchType">搜索数据的类型</param>
        /// <returns>返回第一个成功搜索到对应数据的节点</returns>
        public Node Search(LinearList list, object objectToSearch, SearchType searchType)
        {
            Node node = list.Head.Next;

            switch (searchType)
            {
                case SearchType.SearchName:
                    while (node != null)
                    {
                        if (node.Name == Convert.ToString(objectToSearch))
                        {
                            return node;
                        }

                        node = node.Next;
                    }

                    break;
                case SearchType.SearchBrand:
                    while (node != null)
                    {
                        if (node.Brand == Convert.ToString(objectToSearch))
                        {
                            return node;
                        }

                        node = node.Next;
                    }

                    break;
                case SearchType.SearchPrice:
                    while (node != null)
                    {
                        if (Math.Abs(node.Price - Convert.ToDouble(objectToSearch)) < 0.001)
                        {
                            return node;
                        }

                        node = node.Next;
                    }

                    break;
                case SearchType.SearchCount:
                    while (node != null)
                    {
                        if (node.Count == Convert.ToInt32(objectToSearch))
                        {
                            return node;
                        }

                        node = node.Next;
                    }

                    break;
            }

            return null;
        }

        /// <summary>
        /// 在链表尾部添加新节点
        /// </summary>
        /// <param name="list">待添加节点的链表</param>
        /// <param name="name">新商品名</param>
        /// <param name="brand">新商品名称</param>
        /// <param name="price">新商品单价</param>
        /// <param name="count">新商品数量</param>
        public void Append(LinearList list, string name, string brand, double price, int count)
        {
            Node node = list.Head;

            while (node.Next != null)
            {
                node = node.Next;
            }

            Insert(node, name, brand, price, count);
        }

        /// <summary>
        /// 输出指定节点的所有信息
        /// </summary>
        /// <param name="node">指定节点</param>
        public void PrintNodeData(Node node)
        {
            if (node == null)
            {
                Console.WriteLine("Empty node");
                return;
            }

            Console.Write("\tname:" + node.Name);
            Console.Write("\tbrand:" + node.Brand);
            Console.Write("\tprice:" + node.Price);
            Console.WriteLine("\tcount:" + node.Count);
        }
    }
}