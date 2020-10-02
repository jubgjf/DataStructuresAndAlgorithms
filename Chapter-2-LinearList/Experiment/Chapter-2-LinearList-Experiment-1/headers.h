#pragma once


/* libs */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


/* Calculator.cpp */

/// <summary>
/// �ж��ַ��Ƿ�Ϊ��������"+"��"-"��"*"��"/"
/// </summary>
/// <param name="c">���ж��ַ�</param>
/// <returns>��Ϊ���������򷵻�true�����򷵻�false</returns>
bool IsOperator(char c);

/// <summary>
/// ��ȡ��������ȼ�
/// </summary>
/// <param name="op">�����</param>
/// <returns>������������ȼ�</returns>
int GetPriority(char op);

/// <summary>
/// ��׺���ʽת��Ϊ��׺���ʽ
/// </summary>
/// <param name="infixStr">��׺���ʽ�ַ���</param>
/// <returns>���غ�׺���ʽ�ַ���</returns>
string InfixToSuffix(string infixStr);

/// <summary>
/// ��׺���ʽ��ֵ
/// </summary>
/// <param name="suffixStr">��׺���ʽ�ַ���</param>
/// <returns>������ֵ���</returns>
double CalculateSuffix(string suffixStr);

/// <summary>
/// �����������ֵ�����
/// </summary>
/// <param name="num1">��һ������</param>
/// <param name="num2">�ڶ�������</param>
/// <param name="op">�����</param>
/// <returns>����������</returns>
double ExecCalculate(double num1, double num2, char op);


/* Experiment1.cpp */

/// <summary>
/// ʵ��һ����
/// </summary>
void TestExperiment1();


/* Stack.cpp */

/// <summary>
/// ջ������
/// </summary>
union data
{
    double num;
    char op;
};

/// <summary>
/// ջ�Ľڵ�
/// </summary>
struct node
{
    union data data;
    struct node* next;
};

/// <summary>
/// ��ʼ����ջ
/// </summary>
/// <returns>���ؿ�ջ</returns>
node* InitStack();

/// <summary>
/// ������ѹջ
/// </summary>
/// <param name="stack">ջ</param>
/// <param name="c">�ַ�</param>
void Push(node* stack, char c);

/// <summary>
/// ������ѹջ
/// </summary>
/// <param name="stack">ջ</param>
/// <param name="num">����</param>
void Push(node* stack, double num);

/// <summary>
/// ��ջ
/// </summary>
/// <param name="stack">ջ</param>
/// <returns>����ԭջ���ڵ�ָ�롣��Ϊ��ջ���򷵻�nullptr</returns>
node* Pop(node* stack);

/// <summary>
/// ��ȡջ���ڵ�
/// </summary>
/// <param name="stack">ջ</param>
/// <returns>����ջ����㡣��Ϊ��ջ���򷵻�nullptr</returns>
node* Top(node* stack);

/// <summary>
/// ���ջ�Ƿ�Ϊ��
/// </summary>
/// <param name="stack">ջ</param>
/// <returns>��Ϊ��ջ�򷵻�true�����򷵻�false</returns>
bool IsEmpty(node* stack);

/// <summary>
/// ����ջ�ķ�ʽ
/// </summary>
enum TravelType
{
    TravelNumber,
    TravelOperator
};

/// <summary>
/// ����ջ
/// </summary>
/// <param name="stack">ջ</param>
/// <param name="travelType">����ջ�ķ�ʽ</param>
void Travel(node* stack, TravelType travelType);

/// <summary>
/// ����ջ����Ԫ��������ַ���
/// </summary>
/// <param name="stack">ջ</param>
/// <returns>����ջ����Ԫ����ɵ��ַ���</returns>
string Travel(node* stack);


/* String.cpp */

/// <summary>
/// ȥ���ַ�����ͷ�Ŀո�
/// </summary>
/// <param name="str">Դ�ַ���</param>
/// <returns>����ȥ���ո����ַ���</returns>
string Trim(string str);
