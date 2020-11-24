using System;
using System.IO;

namespace Chapter_6_Sort_Homework_1_CSharp
{
    public static class File
    {
        /// <summary>
        /// 生成随机长度的数组，并将数组写入文件
        /// </summary>
        /// <param name="fileName">文件名</param>
        public static void WriteRandomIntToFile(string fileName)
        {
            using StreamWriter sw = new StreamWriter(fileName);
            Random random = new Random();

            int arrayLength = random.Next(1, 10000); // 随机数组长度

            for (int i = 0; i < arrayLength; i++)
            {
                int randomInt = random.Next(-1000, 1000); // 随机数组元素
                sw.Write(randomInt + " ");
            }
        }

        public static int[] ReadArrayFromFile(string fileName)
        {
            try
            {
                using StreamReader sr = new StreamReader(fileName);
                string arrayString = sr.ReadToEnd();
                string[] arrayStrings = arrayString.Split(' ');

                int[] array = new int[arrayStrings.Length-1];
                for (int i = 0; i < arrayStrings.Length-1; i++)
                {
                    array[i] = Convert.ToInt32(arrayStrings[i]);
                }

                return array;
            }
            catch (Exception)
            {
                return null;
            }
        }
    }
}