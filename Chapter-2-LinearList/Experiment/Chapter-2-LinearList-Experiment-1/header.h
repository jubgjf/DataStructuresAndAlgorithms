#pragma once


/* libs */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


/* Calculator.cpp */

/// <summary>
/// 判断字符是否为操作符："+"、"-"、"*"、"/"
/// </summary>
/// <param name="c">待判断字符</param>
/// <returns>若为操作符，则返回true，否则返回false</returns>
bool IsOperator(char c);

/// <summary>
/// 获取运算符优先级
/// </summary>
/// <param name="op">运算符</param>
/// <returns>返回运算符优先级</returns>
int GetPriority(char op);

/// <summary>
/// 中缀表达式转换为后缀表达式
/// </summary>
/// <param name="infixStr">中缀表达式字符串</param>
/// <returns>返回后缀表达式字符串</returns>
string InfixToSuffix(string infixStr);

/// <summary>
/// 后缀表达式求值
/// </summary>
/// <param name="suffixStr">后缀表达式字符串</param>
/// <returns>返回求值结果</returns>
double CalculateSuffix(string suffixStr);

/// <summary>
/// 进行两个数字的运算
/// </summary>
/// <param name="num1">第一个数字</param>
/// <param name="num2">第二个数字</param>
/// <param name="op">运算符</param>
/// <returns>返回运算结果</returns>
double ExecCalculate(double num1, double num2, char op);


/* Experiment1.cpp */

/// <summary>
/// 实验一测试
/// </summary>
void TestExperiment1();


/* Stack.cpp */

/// <summary>
/// 栈的数据
/// </summary>
union data
{
    double num;
    char op;
};

/// <summary>
/// 栈的节点
/// </summary>
struct node
{
    union data data;
    struct node* next;
};

/// <summary>
/// 初始化新栈
/// </summary>
/// <returns>返回空栈</returns>
node* InitStack();

/// <summary>
/// 将数据压栈
/// </summary>
/// <param name="stack">栈</param>
/// <param name="c">字符</param>
void Push(node* stack, char c);

/// <summary>
/// 将数据压栈
/// </summary>
/// <param name="stack">栈</param>
/// <param name="num">数字</param>
void Push(node* stack, double num);

/// <summary>
/// 弹栈
/// </summary>
/// <param name="stack">栈</param>
/// <returns>返回原栈顶节点指针。若为空栈，则返回nullptr</returns>
node* Pop(node* stack);

/// <summary>
/// 获取栈顶节点
/// </summary>
/// <param name="stack">栈</param>
/// <returns>返回栈顶结点。若为空栈，则返回nullptr</returns>
node* Top(node* stack);

/// <summary>
/// 检查栈是否为空
/// </summary>
/// <param name="stack">栈</param>
/// <returns>若为空栈则返回true，否则返回false</returns>
bool IsEmpty(node* stack);

/// <summary>
/// 遍历栈的方式
/// </summary>
enum TravelType
{
    TravelNumber,
    TravelOperator
};

/// <summary>
/// 遍历栈
/// </summary>
/// <param name="stack">栈</param>
/// <param name="travelType">遍历栈的方式</param>
void Travel(node* stack, TravelType travelType);

/// <summary>
/// 遍历栈并将元素输出到字符串
/// </summary>
/// <param name="stack">栈</param>
/// <returns>返回栈所有元素组成的字符串</returns>
string Travel(node* stack);


/* String.cpp */

/// <summary>
/// 去除字符串开头的空格
/// </summary>
/// <param name="str">源字符串</param>
/// <returns>返回去除空格后的字符串</returns>
string Trim(string str);
