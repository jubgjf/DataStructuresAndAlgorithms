using System;
using System.Collections;
using System.IO;

namespace Chapter_3_Tree_Homework_1_CSharp
{
    class Homework1
    {
        /// <summary>
        /// 测试作业一
        /// </summary>
        public static void TestHomework1()
        {
            while (true)
            {
                ShowMenu();
                GetChoice();
            }
        }

        /// <summary>
        /// 显示用户菜单
        /// </summary>
        private static void ShowMenu()
        {
            Console.WriteLine("===== Test for Huffman Code =====" + Environment.NewLine);
            Console.WriteLine("\t1.Read plain text from \"text.txt\" and write encoded content to \"encode.txt\".");
            Console.WriteLine("\t2.Read encoded text from \"encode.txt\" and print in terminal.");
            Console.WriteLine("\t3.Show encode map.");
            Console.WriteLine("\t4.Calculate Compression ratio.");
            Console.WriteLine("\t5.Exit.");
            Console.WriteLine("Please input your choice:");
        }

        /// <summary>
        /// 读取用户选择
        /// </summary>
        private static void GetChoice()
        {
            try
            {
                int choice = int.Parse(Console.ReadLine());

                // 读取文本文件并分析字符频率
                string text = File.ReadTextFromFile("text.txt");
                int[] frequencyResult = File.AnalyzeFrequency(text);

                // 进行哈夫曼编码
                Huffman huffman = new Huffman(frequencyResult);
                BitArray huffmanCode = huffman.StringToHuffmanCode(text);

                switch (choice)
                {
                    case 1:
                        File.WriteEncodedTextToFile("encode.txt", huffmanCode);
                        Console.WriteLine("Finished.");
                        break;
                    case 2:
                        BitArray encodedText = File.ReadEncodedTextFromFile("encode.txt");
                        string decodedText = huffman.HuffmanCodeToString(encodedText);
                        Console.WriteLine(decodedText);
                        break;
                    case 3:
                        // Show encode map
                        huffman.ShowHuffmanCodeMap();
                        break;
                    case 4:
                        int originSize = Convert.ToInt32(new FileInfo("text.txt").Length);
                        int newSize = Convert.ToInt32(new FileInfo("encode.txt").Length);
                        Console.WriteLine((Convert.ToDouble(newSize) / originSize).ToString("P"));
                        break;
                    case 5:
                        Environment.Exit(0);
                        break;
                    default:
                        Console.WriteLine("Please check your input.");
                        break;
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Error: " + e);
                throw;
            }
        }
    }
}