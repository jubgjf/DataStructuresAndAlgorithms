#include <cstdlib>
#include "header.h"

string Init(const char str[])
{
    return const_cast<char*>(str);
}

bool IsEmpty(string str)
{
    return str[0] == '\0';
}

int Len(string str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; ++i, ++len);

    return len;
}

string Insert(string str, string insertStr, int index)
{
    string frontStr = Substr(str, 0, index + 1);
    string backStr = Substr(str, index + 1, Len(str));
    string insertAndBackStr = Concat(insertStr, backStr);
    string resultStr = Concat(frontStr, insertAndBackStr);

    return resultStr;
}

string Delete(string str, string deleteStr)
{
    int deleteIndex = Match_KMP(str, deleteStr);
    string frontStr = Substr(str, 0, deleteIndex);
    string backStr = Substr(str, deleteIndex + Len(deleteStr), Len(str));
    string resultStr = Concat(frontStr, backStr);

    return resultStr;
}

string Concat(string str1, string str2)
{
    string resultStr = static_cast<string>(malloc(Len(str1) + Len(str2) + 1));
    int i, j;

    for (i = 0; str1[i] != '\0'; ++i)
    {
        resultStr[i] = str1[i];
    }
    for (j = 0; str2[j] != '\0'; ++j)
    {
        resultStr[i + j] = str2[j];
    }
    resultStr[i + j] = '\0';

    return resultStr;
}

string Substr(string str, int startIndex, int endIndex)
{
    if (startIndex < 0) { startIndex = 0; }
    if (endIndex > Len(str)) { endIndex = Len(str); }

    // TODO 从Delete跳转至此时，malloc和new都报错：触发断点
    string resultStr = static_cast<string>(malloc(endIndex - startIndex + 1));
    // string resultStr = new char[endIndex - startIndex + 1];
    int j = 0;

    for (int i = startIndex; i < endIndex; ++i, ++j)
    {
        resultStr[j] = str[i];
    }
    resultStr[j] = '\0';

    return resultStr;
}

int Match_BF(string str, string pattern)
{
    int i = 0, j = 0;

    while (i < Len(str) && j < Len(pattern))
    {
        if (str[i] != pattern[j])
        {
            i = i - j + 1; // i回溯
            j = 0; // j复位
        }
        else
        {
            i++;
            j++;
        }
    }

    if (j == Len(pattern))
    {
        return i - Len(pattern);
    }

    return -1;
}

int Match_KMP(string str, string pattern)
{
    int i = 0, j = 0;
    int* next = GetNext(pattern);

    while (i < Len(str) && j < Len(pattern))
    {
        if (str[i] != pattern[j] && j != -1)
        {
            j = next[j];
        }
        else
        {
            i++;
            j++;
        }
    }

    if (j == Len(pattern))
    {
        return i - Len(pattern);
    }

    return -1;
}

int* GetNext(string pattern)
{
    int* next = static_cast<int*>(malloc(Len(pattern)));
    next[0] = -1;
    int prefixIndex = 0, suffixIndex = -1;

    while (prefixIndex < Len(pattern))
    {
        if (suffixIndex == -1 || pattern[prefixIndex] == pattern[suffixIndex])
        {
            prefixIndex++;
            suffixIndex++;
            next[prefixIndex] = suffixIndex;
        }
        else
        {
            suffixIndex = next[suffixIndex];
        }
    }

    return next;
}
