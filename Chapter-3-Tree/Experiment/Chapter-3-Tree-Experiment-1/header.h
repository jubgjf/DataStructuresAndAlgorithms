#pragma once

/**
 * \brief ���нڵ㴢�����������
 */
typedef char elementType;

/// <summary>
/// ���Ľڵ�
/// </summary>
struct node
{
    elementType data;
    struct node* leftChild;
    struct node* rightChild;
};

/**
 * \brief ������
 */
typedef node* Tree;

/// <summary>
/// ���������е������һ������
/// </summary>
/// <param name="rootData">�������ڵ�����</param>
/// <param name="leftTree">������</param>
/// <param name="rightTree">������</param>
/// <returns>��������</returns>
Tree Init(elementType rootData, Tree leftTree, Tree rightTree);

/// <summary>
/// �����������ȡ�û��������
/// </summary>
/// <returns>�����������</returns>
Tree InputTree();

/// <summary>
/// ������������ǵݹ�
/// </summary>
/// <param name="tree">��</param>
void PreOrderTravel(Tree tree);

/// <summary>
/// ������������ݹ�
/// </summary>
/// <param name="tree">��</param>
void PreOrderTravel_Recurse(Tree tree);

/// <summary>
/// ������������ǵݹ�
/// </summary>
/// <param name="tree">��</param>
void InOrderTravel(Tree tree);

/// <summary>
/// ������������ݹ�
/// </summary>
/// <param name="tree">��</param>
void InOrderTravel_Recurse(Tree tree);

/// <summary>
/// ������������ǵݹ�
/// </summary>
/// <param name="tree">��</param>
void PostOrderTravel(Tree tree);

/// <summary>
/// ������������ݹ�
/// </summary>
/// <param name="tree">��</param>
void PostOrderTravel_Recurse(Tree tree);

/// <summary>
/// ���������
/// </summary>
/// <param name="tree">��</param>
void LayerTravel(Tree tree);

/// <summary>
/// �ж����Ƿ�Ϊ������
/// </summary>
/// <param name="tree">��</param>
/// <returns>�����Ƿ�Ϊ�������Ľ��</returns>
bool IsBinaryTree(Tree tree);

/// <summary>
/// ��ȡ�����ڵ�Ĺ�������
/// </summary>
/// <param name="tree">��</param>
/// <param name="node1">��һ���ڵ�</param>
/// <param name="node2">�ڶ����ڵ�</param>
/// <returns>���������ڵ�ĵ�һ����������</returns>
node* GetPublicAncestor(Tree tree, node* node1, node* node2);
