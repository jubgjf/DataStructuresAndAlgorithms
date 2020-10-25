using System;

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
            // heap.Insert(new Heap.CharData { Char = 'a', Frequency = 1 });
            // heap.Insert(new Heap.CharData { Char = 'b', Frequency = 2 });
            // heap.Insert(new Heap.CharData { Char = 'c', Frequency = 3 });
            // heap.Insert(new Heap.CharData { Char = 'd', Frequency = 4 });
            // heap.Insert(new Heap.CharData { Char = 'e', Frequency = 5 });
            // heap.Insert(new Heap.CharData { Char = 'f', Frequency = 3 });
            // heap.Insert(new Heap.CharData { Char = 'g', Frequency = 4 });
            // heap.Insert(new Heap.CharData { Char = 'h', Frequency = 5 });
            // heap.Insert(new Heap.CharData { Char = 'i', Frequency = 6 });
            // heap.Insert(new Heap.CharData { Char = 'j', Frequency = 2 });
            // heap.Pop();
            // heap.Pop();
            // heap.Pop();

            int[] charData = new int[128];
            charData[65] = 12;  // A
            charData[68] = 29;  // D
            charData[79] = 8;   // O
            charData[90] = 77;  // Z
            charData[125] = 1;  // }

            Huffman huffman=new Huffman(charData);
        }
    }
}