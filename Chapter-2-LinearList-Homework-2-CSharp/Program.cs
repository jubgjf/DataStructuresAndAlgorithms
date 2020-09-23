using System;

namespace Chapter_2_LinearList_Homework_2_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            LinearList list;

            Console.WriteLine("===== Test for Homework 2 =====");
            Console.WriteLine(Environment.NewLine);

            if (FileIO.IsFileExit())
            {
                list = FileIO.ReadListFromFile();
                Console.WriteLine("Automatically read data from file -- success.");
            }
            else
            {
                list = new LinearList();
                Console.WriteLine("Automatically read data from file -- fail.");
                Console.WriteLine("An empty linear list has been created.");
            }

            Console.WriteLine(Environment.NewLine);


            while (true)
            {
                Homework2.PrintMenu();
                Homework2.GetChoice(list);
            }
        }
    }
}