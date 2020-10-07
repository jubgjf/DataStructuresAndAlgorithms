#pragma once


/* String.cpp */

/**
 * \brief �ַ�������
 */
#define string char*

/// <summary>
/// �½��ַ���
/// </summary>
/// <param name="str">char�����ַ���</param>
/// <returns>�����½��ַ���</returns>
string Init(const char str[]);

/// <summary>
/// �ж��ַ����Ƿ�Ϊ��
/// </summary>
/// <param name="str">�ַ���</param>
/// <returns>���ַ���Ϊ���򷵻�true�����򷵻�false</returns>
bool IsEmpty(string str);

/// <summary>
/// ��ȡ�ַ�������
/// </summary>
/// <param name="str">�ַ���</param>
/// <returns>�����ַ�������</returns>
int Len(string str);

/// <summary>
/// ���ַ������뵽Ŀ���ַ���ָ��λ��֮��
/// </summary>
/// <param name="str">ԭ�ַ���</param>
/// <param name="insertStr">�������ַ���</param>
/// <param name="index">����λ��</param>
/// <returns>���ز����ַ�����Ľ��</returns>
string Insert(string str, string insertStr, int index);

/// <summary>
/// ���ַ�����ɾ�����ַ���
/// </summary>
/// <param name="str">ԭ�ַ���</param>
/// <param name="deleteStr">��ɾ�������ַ���</param>
/// <returns>����ɾ����Ľ��</returns>
string Delete(string str, string deleteStr);

/// <summary>
/// ���������ַ���
/// </summary>
/// <param name="str1">��һ���ַ���</param>
/// <param name="str2">�ڶ����ַ���</param>
/// <returns>�����ַ���ƴ�ӽ��</returns>
string Concat(string str1, string str2);

/// <summary>
/// ���ַ����н�ȡ���ַ���
/// </summary>
/// <param name="str">ԭ�ַ���</param>
/// <param name="startIndex">��ȡ��ʼλ��</param>
/// <param name="endIndex">��ȡ����λ��</param>
/// <returns>���ؽ�ȡ�����ַ���</returns>
string Substr(string str, int startIndex, int endIndex);

/// <summary>
/// ���ַ�����Ѱ�����ַ���λ�ã�ʹ��BF�㷨
/// </summary>
/// <param name="str">�ַ���</param>
/// <param name="pattern">�����ҵ����ַ���</param>
/// <returns>�������ַ�����һ�γ��ֵ�λ��</returns>
int Match_BF(string str, string pattern);

/// <summary>
/// ���ַ�����Ѱ�����ַ���λ�ã�ʹ��KMP�㷨
/// </summary>
/// <param name="str">�ַ���</param>
/// <param name="pattern">�����ҵ����ַ���</param>
/// <returns>�������ַ�����һ�γ��ֵ�λ��</returns>
int Match_KMP(string str, string pattern);

/// <summary>
/// ��ȡKMP�㷨��Ҫ��next����
/// </summary>
/// <param name="pattern">ģʽ�ַ���</param>
/// <returns>����next����</returns>
int* GetNext(string pattern);
