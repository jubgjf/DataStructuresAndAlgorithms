using System.IO;

namespace Chapter_4_Graph_Experiment_1_CSharp
{
    static class FileIO
    {
        /// <summary>
        /// 获取文件中矩阵的宽度
        /// </summary>
        /// <param name="fileName">文件路径</param>
        /// <returns>返回矩阵宽度</returns>
        public static int GetMatrixWidthFromFile(string fileName)
        {
            using StreamReader sr = new StreamReader(fileName);

            string firstLine = sr.ReadLine();
            string[] numString = firstLine.Split(' ');

            return numString.Length;
        }

        /// <summary>
        /// 从文件中读取邻接矩阵
        /// </summary>
        /// <param name="fileName">文件路径</param>
        /// <returns>返回邻接矩阵</returns>
        public static int[,] ReadMatrixFromFile(string fileName)
        {
            int nodeCount = GetMatrixWidthFromFile(fileName);
            int[,] matrix = new int[nodeCount, nodeCount];

            using StreamReader sr = new StreamReader(fileName);

            for (int i = 0; i < nodeCount; i++)
            {
                string line = sr.ReadLine();
                string[] numString = line.Split(' ');
                for (int j = 0; j < nodeCount; j++)
                {
                    matrix[i, j] = int.Parse(numString[j]);
                }
            }

            return matrix;
        }

        /// <summary>
        /// 获取文件行数
        /// </summary>
        /// <param name="fileName">文件路径</param>
        /// <returns>返回文件行数</returns>
        public static int GetFileLinesCount(string fileName)
        {
            using StreamReader sr = new StreamReader(fileName);
            int count = 0;

            while (sr.ReadLine() != null) { count++; }

            return count;
        }

        /// <summary>
        /// 从文件中读取邻接表
        /// </summary>
        /// <param name="fileName">文件路径</param>
        /// <returns>返回邻接表</returns>
        public static int[][] ReadListFromFile(string fileName)
        {
            using StreamReader sr = new StreamReader(fileName);
            int linesCount = GetFileLinesCount(fileName);
            int[][] list = new int[linesCount][];

            for (int i = 0; i < linesCount; i++)
            {
                string lineString = sr.ReadLine();
                string[] numString = lineString.Split(' ');
                int[] lineNum = new int[numString.Length];
                for (int j = 0; j < numString.Length; j++)
                {
                    lineNum[j] = int.Parse(numString[j]);
                }

                list[i] = lineNum;
            }

            return list;
        }
    }
}
