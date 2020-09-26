using System;
using System.IO;

namespace Chapter_2_LinearList_Homework_2_CSharp
{
    static class FileIO
    {
        /// <summary>
        /// 写入文件默认位置
        /// </summary>
        public const string FileName = "data.txt";

        /// <summary>
        /// 将链表中的所有数据写入文件
        /// </summary>
        /// <param name="list">待保存的链表</param>
        /// <param name="fileName">写入文件的位置</param>
        public static void WriteListToFile(LinearList list, string fileName = FileName)
        {
            Node node = list.Head.Next;
            bool append = false;

            while (node != null)
            {
                using StreamWriter sw = new StreamWriter(fileName, append: append);
                sw.WriteLine(node.Name + "@" + node.Brand + "@" + node.Price + "@" + node.Count);

                append = true;
                node = node.Next;
            }
        }

        /// <summary>
        /// 将文件中的数据读取到链表中
        /// </summary>
        /// <param name="fileName">待读取的文件</param>
        /// <returns>返回读取文件后的链表</returns>
        public static LinearList ReadListFromFile(string fileName = FileName)
        {
            LinearList list = new LinearList();

            using StreamReader sr = new StreamReader(fileName);
            string allData = sr.ReadToEnd();
            string[] lines = allData.Split(Environment.NewLine, StringSplitOptions.RemoveEmptyEntries);

            foreach (string line in lines)
            {
                string[] rawData = line.Split("@");
                list.Append(list, rawData[0], rawData[1],
                    Convert.ToDouble(rawData[2]), Convert.ToInt32(rawData[3]));
            }

            return list;
        }

        /// <summary>
        /// 判断文件是否存在
        /// </summary>
        /// <param name="fileName">待判断的文件</param>
        /// <returns>存在则返回true，否则返回false</returns>
        public static bool IsFileExit(string fileName = FileName)
        {
            return File.Exists(fileName);
        }
    }
}