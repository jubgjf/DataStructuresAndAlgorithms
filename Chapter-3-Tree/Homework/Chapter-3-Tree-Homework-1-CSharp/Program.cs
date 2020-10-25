using System;
using System.Collections;

namespace Chapter_3_Tree_Homework_1_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            // 读取文本文件并分析字符频率
            string text = File.ReadTextFromFile("test.txt");
            int[] frequencyResult = File.AnalyzeFrequency(text);
            
            // 进行哈夫曼编码
            Huffman huffman = new Huffman(frequencyResult);
            BitArray huffmanCode = huffman.StringToHuffmanCode(text);
            
            // 将编码写入二进制文件
            File.WriteEncodedTextToFile("result.txt", huffmanCode);

            // 读取二进制文件并进行解码
            BitArray encodedText = File.ReadEncodedTextFromFile("result.txt");
            string decodedText = huffman.HuffmanCodeToString(encodedText);
            
            // 输出解码结果
            Console.WriteLine(decodedText);
        }
    }
}