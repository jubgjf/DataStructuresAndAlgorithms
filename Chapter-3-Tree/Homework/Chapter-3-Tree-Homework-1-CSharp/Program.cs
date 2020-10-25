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

            // Heap heap = new Heap();
            // heap.Insert(new Heap.CharData { Char = 'a', Weight = 1 });
            // heap.Insert(new Heap.CharData { Char = 'b', Weight = 2 });
            // heap.Insert(new Heap.CharData { Char = 'c', Weight = 3 });
            // heap.Insert(new Heap.CharData { Char = 'd', Weight = 4 });
            // heap.Insert(new Heap.CharData { Char = 'e', Weight = 5 });
            // heap.Insert(new Heap.CharData { Char = 'f', Weight = 3 });
            // heap.Insert(new Heap.CharData { Char = 'g', Weight = 4 });
            // heap.Insert(new Heap.CharData { Char = 'h', Weight = 5 });
            // heap.Insert(new Heap.CharData { Char = 'i', Weight = 6 });
            // heap.Insert(new Heap.CharData { Char = 'j', Weight = 2 });
            // heap.Pop();
            // heap.Pop();
            // heap.Pop();

            int[] charData = new int[128];
            charData[Convert.ToInt32('A')] = 12;
            charData[Convert.ToInt32('D')] = 29;
            charData[Convert.ToInt32('O')] = 8;
            charData[Convert.ToInt32('Z')] = 77;
            charData[Convert.ToInt32('}')] = 1;

            Huffman huffman = new Huffman(charData);
        }
    }
}