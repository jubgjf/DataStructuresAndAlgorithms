﻿using System;
using System.IO;

namespace Chapter_3_Tree_Homework_1_CSharp
{
    static class File
    {
        /// <summary>
        /// 从文件中读取所有字符
        /// </summary>
        /// <param name="fileName">文件路径</param>
        /// <returns>返回读取的字符串，若找不到文件则返回null</returns>
        public static string ReadTextFromFile(string fileName)
        {
            try
            {
                using StreamReader sr = new StreamReader(fileName);
                return sr.ReadToEnd();
            }
            catch (Exception)
            {
                return null;
            }
        }

        /// <summary>
        /// 将字符串写入文件
        /// </summary>
        /// <param name="fileName">文件路径</param>
        /// <param name="text">代写入的字符串</param>
        public static void WriteTextToFile(string fileName, string text)
        {
            using StreamWriter sw = new StreamWriter(fileName);
            sw.Write(text);
        }

        /// <summary>
        /// 字符分析数组的最大长度（ASCII所有字符的个数）
        /// </summary>
        private const int MaxCharKinds = 128;

        /// <summary>
        /// 分析字符串中各个字符的出现次数
        /// </summary>
        /// <param name="text">待分析的字符串</param>
        /// <returns>返回分析结果数组，字符的ASCII码是数组下标位置</returns>
        public static int[] AnalyzeFrequency(string text)
        {
            int[] charData = new int[MaxCharKinds];
            foreach (char c in text)
            {
                charData[Convert.ToInt32(c)]++;
            }

            return charData;
        }
    }
}