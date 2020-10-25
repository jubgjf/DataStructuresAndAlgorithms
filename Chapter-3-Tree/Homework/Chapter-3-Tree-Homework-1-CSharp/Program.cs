using System;
using System.Collections;

namespace Chapter_3_Tree_Homework_1_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            // File.WriteTextToFile("test.txt", "first\r\nsecond");
            // string text = File.ReadTextFromFile("test.txt");
            // int[] analyzeResult = File.AnalyzeFrequency(text);

            int[] charData = new int[128];
            charData[Convert.ToInt32('A')] = 12;
            charData[Convert.ToInt32('D')] = 29;
            charData[Convert.ToInt32('O')] = 8;
            charData[Convert.ToInt32('Z')] = 77;
            charData[Convert.ToInt32('K')] = 1;

            Huffman huffman = new Huffman(charData);

            BitArray bitArray = huffman.StringToHuffmanCode("AZKDOZAA");

            string str = huffman.HuffmanCodeToString(new BitArray(new bool[]
            {
                true, true, false,
                false,
                true, true, true, false,
                true, false,
                true, true, true, true,
                false,
                true, true, false,
                true, true, false
            })); // AZKDOZAA
        }
    }
}