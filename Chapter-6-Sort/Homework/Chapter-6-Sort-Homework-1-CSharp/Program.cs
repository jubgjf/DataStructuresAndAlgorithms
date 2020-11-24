using System;

namespace Chapter_6_Sort_Homework_1_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            // File.WriteRandomIntToFile("array.txt");

            int[] array = File.ReadArrayFromFile("array.txt");

            DateTime startTime = DateTime.Now; // 开始计时

            // Sort.BubbleSort(ref array);
            // Sort.QuickSort(ref array, 0, array.Length - 1);
            // Sort.SelectSort(ref array);
            // Sort.HeapSort(ref array);
            // Sort.InsertSort(ref array);
            // Sort.ShellSort(ref array);

            DateTime endTime = DateTime.Now; // 结束计时

            // PrintArray(array);

            TimeSpan timeSpan = endTime.Subtract(startTime);
            Console.WriteLine(Environment.NewLine + "Time Cost:" + timeSpan);
        }

        /// <summary>
        /// 输出数组
        /// </summary>
        /// <param name="array">数组</param>
        static void PrintArray(int[] array)
        {
            foreach (int i in array)
            {
                Console.Write(i + " ");
            }
        }
    }
}