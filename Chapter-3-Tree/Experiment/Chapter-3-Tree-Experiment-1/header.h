#pragma once


/* Stack.cpp */

/**
 * \brief ջ�Ĵ洢�����ռ�
 */
#define MAX_STACK_SIZE 1000

 /// <summary>
 /// ջ�Ĵ洢��
 /// </summary>
struct Stack
{
    struct Node* storePool[MAX_STACK_SIZE];
    int topIndex;
};

/// <summary>
/// ��ʼ��ջ
/// </summary>
/// <returns>���ؿ�ջ</returns>
Stack* InitStack();

/// <summary>
/// �ж�ջ�Ƿ�Ϊ��
/// </summary>
/// <param name="stack">ջ</param>
/// <returns>����ջΪ�յĽ��</returns>
bool IsEmpty(Stack* stack);

/// <summary>
/// ������ѹջ
/// </summary>
/// <param name="stack">ջ</param>
/// <param name="data">��ѹջ����</param>
void Push(Stack* stack, struct Node* data);

/// <summary>
/// ��ջ
/// </summary>
/// <param name="stack">ջ</param>
/// <returns>���ص�����Ԫ��</returns>
struct Node* Pop(Stack* stack);

/// <summary>
/// ��ȡջ��Ԫ��
/// </summary>
/// <param name="stack">ջ</param>
/// <returns>����ջ��Ԫ��</returns>
struct Node* Top(Stack* stack);

/// <summary>
/// ���򴢴�һ��ջ
/// </summary>
/// <param name="stack">ջ</param>
/// <returns>���������ջ</returns>
Stack* Reverse(Stack* stack);


/* Queue.cpp */

/// <summary>
/// ������ջģ��Ķ��нṹ
/// </summary>
struct Queue
{
    Stack* enqueueStack;
    Stack* dequeueStack;
};

/// <summary>
/// ��ʼ������
/// </summary>
/// <returns>���ؿն���</returns>
Queue* InitQueue();

/// <summary>
/// ��ѯ�����Ƿ�Ϊ��
/// </summary>
/// <param name="queue">����</param>
/// <returns>���ض����Ƿ�Ϊ��</returns>
bool IsEmpty(Queue* queue);

/// <summary>
/// ���
/// </summary>
/// <param name="queue">����</param>
/// <param name="data">�����Ԫ��</param>
void Enqueue(Queue* queue, struct Node* data);

/// <summary>
/// ����
/// </summary>
/// <param name="queue">����</param>
/// <returns>���س���Ԫ��</returns>
struct Node* Dequeue(Queue* queue);


/* Tree.cpp */

/**
 * \brief �������ڵ����
 */
#define MAX_NODE_COUNT 500

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
/// ��ȡָ���ڵ㵽���ڵ��·��
/// </summary>
/// <param name="tree">��</param>
/// <param name="node">�ڵ�</param>
/// <param name="nodePathToRoot">��ָ���ڵ㵽����·��</param>
/// <param name="found">�ҵ�·���ı�־�����������ݹ�</param>
void GetPathToRoot(Tree tree, Node* node, Stack* nodePathToRoot, bool* found);

/// <summary>
/// ��ȡ�����ڵ�Ĺ�������
/// </summary>
/// <param name="tree">��</param>
/// <param name="node1">��һ���ڵ�</param>
/// <param name="node2">�ڶ����ڵ�</param>
/// <returns>���������ڵ�����й�������</returns>
Node** GetPublicAncestors(Tree tree, Node* node1, Node* node2);

/// <summary>
/// ��ȡ�����ڵ�Ĺ�������
/// </summary>
/// <param name="tree">��</param>
/// <param name="node1Data">��һ���ڵ㴢�������</param>
/// <param name="node2Data">�ڶ����ڵ㴢�������</param>
/// <returns>���������ڵ�����й�������</returns>
Node** GetPublicAncestors(Tree tree, elementType node1Data, elementType node2Data);

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
