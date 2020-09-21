#pragma once

#include <fstream>
#include <iostream>
#include <regex>
#include "BasicOperations.h"

#define DATA_FILE_NAME "data.txt"

/// <summary>
/// 写入文件操作的方式
/// </summary>
enum WRITE_FILE_TYPE
{
    APPEND,
    OVERWRITE
};

// TODO 注释
inline void WriteDataToFile(Data data, enum WRITE_FILE_TYPE writeFileType = APPEND,
                            const std::string fileName = DATA_FILE_NAME)
{
    std::ofstream outfile;

    switch (writeFileType)
    {
    case APPEND:
        outfile.open(fileName, std::ios::app);
        break;
    case OVERWRITE:
        outfile.open(fileName);
        break;
    }

    outfile << data.name << " ";
    outfile << data.brand << " ";
    outfile << data.price << " ";
    outfile << data.count << std::endl;

    outfile.close();
}

// TODO 注释
inline void WriteListToFile(Cell* list, const std::string fileName = DATA_FILE_NAME)
{
}

// TODO 注释
inline Cell* ReadListFromFile(const std::string fileName = DATA_FILE_NAME)
{
    std::ifstream infile(fileName);
    std::string line;
    std::regex pattern("\\s+"); // 空格
    Data data;

    if (infile) // 存在该文件
    {
        while (getline(infile, line))
        {
            std::vector<std::string> v(
                std::sregex_token_iterator(line.begin(), line.end(), pattern, -1),
                std::sregex_token_iterator());
            data.name = v[0];
            data.brand = v[1];
            data.price = stod(v[2]);
            data.count = stoi(v[3]);

            // TODO 生成链表
        }
    }
    else
    {
    }

    return nullptr;
}
