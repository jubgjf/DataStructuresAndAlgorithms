#pragma once


/* String.cpp */

/**
 * \brief 字符串类型
 */
#define string char*

/// <summary>
/// 新建字符串
/// </summary>
/// <param name="str">char数组字符串</param>
/// <returns>返回新建字符串</returns>
string Init(const char str[]);

/// <summary>
/// 判断字符串是否为空
/// </summary>
/// <param name="str">字符串</param>
/// <returns>若字符串为空则返回true，否则返回false</returns>
bool IsEmpty(string str);

/// <summary>
/// 获取字符串长度
/// </summary>
/// <param name="str">字符串</param>
/// <returns>返回字符串长度</returns>
int Len(string str);

/// <summary>
/// 将字符串插入到目标字符串指定位置之后
/// </summary>
/// <param name="str">原字符串</param>
/// <param name="insertStr">待插入字符串</param>
/// <param name="index">插入位置</param>
/// <returns>返回插入字符串后的结果</returns>
string Insert(string str, string insertStr, int index);

/// <summary>
/// 在字符串中删除子字符串
/// </summary>
/// <param name="str">原字符串</param>
/// <param name="deleteStr">待删除的子字符串</param>
/// <returns>返回删除后的结果</returns>
string Delete(string str, string deleteStr);

/// <summary>
/// 连接两个字符串
/// </summary>
/// <param name="str1">第一个字符串</param>
/// <param name="str2">第二个字符串</param>
/// <returns>返回字符串拼接结果</returns>
string Concat(string str1, string str2);

/// <summary>
/// 从字符串中截取子字符串
/// </summary>
/// <param name="str">原字符串</param>
/// <param name="startIndex">截取开始位置</param>
/// <param name="endIndex">截取结束位置</param>
/// <returns>返回截取的子字符串</returns>
string Substr(string str, int startIndex, int endIndex);

/// <summary>
/// 在字符串中寻找子字符串位置，使用BF算法
/// </summary>
/// <param name="str">字符串</param>
/// <param name="pattern">待查找的子字符串</param>
/// <returns>返回子字符串第一次出现的位置</returns>
int Match_BF(string str, string pattern);

/// <summary>
/// 在字符串中寻找子字符串位置，使用KMP算法
/// </summary>
/// <param name="str">字符串</param>
/// <param name="pattern">待查找的子字符串</param>
/// <returns>返回子字符串第一次出现的位置</returns>
int Match_KMP(string str, string pattern);

/// <summary>
/// 获取KMP算法需要的next数组
/// </summary>
/// <param name="pattern">模式字符串</param>
/// <returns>返回next数组</returns>
int* GetNext(string pattern);
