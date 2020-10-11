#pragma once

#include <string>
#include <vector>


/* Tree.cpp */

/**
 * \brief ���нڵ㴢�����������
 */
typedef char elementType;

/// <summary>
/// ���Ľڵ�
/// </summary>
struct Node
{
    elementType data;
    struct Node* leftChild;
    struct Node* rightChild;
};

/**
 * \brief ������
 */
typedef Node* Tree;

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
/// �ж϶������Ƿ�Ϊ��ȫ������
/// </summary>
/// <param name="tree">������</param>
/// <returns>�����Ƿ�Ϊ��ȫ�������Ľ��</returns>
bool IsCompleteBinaryTree(Tree tree);

/// <summary>
/// ��ȡ���ڵ㵽ָ���ڵ��·��
/// </summary>
/// <param name="tree">��</param>
/// <param name="node">�ڵ�</param>
/// <param name="tempPath">�ݹ�ʱ����ʱ·��</param>
/// <param name="finalPath">����·��</param>
void GetPathFromRoot(Tree tree, Node* node, std::vector<Node*>& tempPath, std::vector<Node*>& finalPath);

/// <summary>
/// ��ȡ�����ڵ�Ĺ�������
/// </summary>
/// <param name="tree">��</param>
/// <param name="node1">��һ���ڵ�</param>
/// <param name="node2">�ڶ����ڵ�</param>
/// <returns>���������ڵ�����й�������</returns>
std::vector<Node*> GetPublicAncestors(Tree tree, Node* node1, Node* node2);

/// <summary>
/// ��ȡ�����ڵ�Ĺ�������
/// </summary>
/// <param name="tree">��</param>
/// <param name="node1Data">��һ���ڵ㴢�������</param>
/// <param name="node2Data">�ڶ����ڵ㴢�������</param>
/// <returns>���������ڵ�����й�������</returns>
std::vector<Node*> GetPublicAncestors(Tree tree, elementType node1Data, elementType node2Data);

/// <summary>
/// ��������Ѱ�ҽڵ�
/// </summary>
/// <param name="tree">��</param>
/// <param name="data">��֪����</param>
/// <returns>���ش洢��֪���ݵĽڵ�</returns>
Node* FindNodeByData(Tree tree, elementType data);


/* Experiment.cpp */

/// <summary>
/// ����ʵ��һ
/// </summary>
void TestExperiment1();
