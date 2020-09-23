using System;

namespace Chapter_2_LinearList_Homework_2_CSharp
{
    static class Homework2
    {
        /// <summary>
        /// 输出菜单
        /// </summary>
        public static void PrintMenu()
        {
            Console.WriteLine("Functions available:");
            Console.WriteLine(Environment.NewLine);
            Console.WriteLine("\t1.Add a new appliance.");
            Console.WriteLine("\t2.Pick up appliances.");
            Console.WriteLine("\t3.Search information.");
            Console.WriteLine("\t4.Update information.");
            Console.WriteLine("\t5.Show all appliances.");
            Console.WriteLine("\t6.Exit.(Automatically write data to file)");
            Console.WriteLine(Environment.NewLine);
            Console.WriteLine("Please input your choice: (1 ~ 6)");
        }

        /// <summary>
        /// 接受用户输入
        /// </summary>
        /// <param name="list">链表</param>
        public static void GetChoice(LinearList list)
        {
            int choice = Convert.ToInt32(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    AddNewAppliance(list);
                    break;
                case 2:
                    PickUpAppliance(list);
                    break;
                case 3:
                    SearchInformation(list);
                    break;
                case 4:
                    UpdateInformation(list);
                    break;
                case 5:
                    ShowList(list);
                    break;
                case 6:
                    FileIO.WriteListToFile(list);
                    Environment.Exit(0);
                    break;
                default:
                    Console.WriteLine("Please check your input.");
                    break;
            }
        }

        /// <summary>
        /// 添加新电器
        /// </summary>
        /// <param name="list">链表</param>
        public static void AddNewAppliance(LinearList list)
        {
            Console.Write("input name:\t");
            string name = Console.ReadLine();
            Console.Write("input brand:\t");
            string brand = Console.ReadLine();
            Console.Write("input price:\t");
            double price = Convert.ToDouble(Console.ReadLine());
            Console.Write("input count:\t");
            int count = Convert.ToInt32(Console.ReadLine());

            list.InsertByPrice(list, name, brand, price, count);
        }

        /// <summary>
        /// 提货
        /// </summary>
        /// <param name="list">链表</param>
        public static void PickUpAppliance(LinearList list)
        {
            Console.Write("input name:\t");
            string name = Console.ReadLine();

            Node searchResult = list.Search(list, name, LinearList.SearchType.SearchName);

            if (searchResult == null || searchResult.Count <= 0)
            {
                Console.WriteLine("No such appliance or sold out.");
            }
            else
            {
                Console.WriteLine("Your appliance:");
                list.PrintNodeData(searchResult);

                searchResult.Count -= 1;
            }
        }

        /// <summary>
        /// 查找信息
        /// </summary>
        /// <param name="list">链表</param>
        public static void SearchInformation(LinearList list)
        {
            Console.WriteLine("input your search type:");
            Console.WriteLine("\t1.search for name");
            Console.WriteLine("\t2.search for brand");
            Console.WriteLine("\t3.search for price");
            Console.WriteLine("\t4.search for count");

            int choice = Convert.ToInt32(Console.ReadLine());

            Console.Write("input your keyword:\t");
            string input = Console.ReadLine();

            Node searchResult;

            switch (choice)
            {
                case 1:
                    searchResult = list.Search(list, input, LinearList.SearchType.SearchName);
                    break;
                case 2:
                    searchResult = list.Search(list, input, LinearList.SearchType.SearchBrand);
                    break;
                case 3:
                    double searchDouble = Convert.ToDouble(input);
                    searchResult = list.Search(list, searchDouble, LinearList.SearchType.SearchPrice);
                    break;
                case 4:
                    int searchInt = Convert.ToInt32(input);
                    searchResult = list.Search(list, searchInt, LinearList.SearchType.SearchCount);
                    break;
                default:
                    searchResult = null;
                    Console.WriteLine("please check your input.");
                    break;
            }

            list.PrintNodeData(searchResult);
        }

        /// <summary>
        /// 更新电器信息
        /// </summary>
        /// <param name="list">链表</param>
        public static void UpdateInformation(LinearList list)
        {
            Console.Write("input name:\t");
            string name = Console.ReadLine();

            Node searchResult = list.Search(list, name, LinearList.SearchType.SearchName);

            if (searchResult == null || searchResult.Count <= 0)
            {
                Console.WriteLine("No such appliance or sold out.");
                return;
            }

            Console.Write("input new name:\t");
            string newName = Console.ReadLine();
            Console.Write("input new brand:\t");
            string newBrand = Console.ReadLine();
            Console.Write("input new price:\t");
            double newPrice = Convert.ToDouble(Console.ReadLine());
            Console.Write("input new count:\t");
            int newCount = Convert.ToInt32(Console.ReadLine());

            list.Update(searchResult, newName, newBrand, newPrice, newCount);
        }

        /// <summary>
        /// 输出链表所有信息
        /// </summary>
        /// <param name="list">链表</param>
        public static void ShowList(LinearList list)
        {
            Node node = list.Head.Next;

            while (node.Next != null)
            {
                list.PrintNodeData(node);
                node = node.Next;
            }
        }
    }
}