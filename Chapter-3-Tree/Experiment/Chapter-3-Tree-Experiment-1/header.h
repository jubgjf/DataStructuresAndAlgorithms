#pragma once


/* Stack.cpp */

/**
 * \brief 栈的存储池最大空间
 */
#define MAX_STACK_SIZE 1000

 /// <summary>
 /// 栈的存储池
 /// </summary>
struct Stack
{
    struct Node* storePool[MAX_STACK_SIZE];
    int topIndex;
};

/// <summary>
/// 初始化栈
/// </summary>
/// <returns>返回空栈</returns>
Stack* InitStack();

/// <summary>
/// 判断栈是否为空
/// </summary>
/// <param name="stack">栈</param>
/// <returns>返回栈为空的结果</returns>
bool IsEmpty(Stack* stack);

/// <summary>
/// 将数据压栈
/// </summary>
/// <param name="stack">栈</param>
/// <param name="data">待压栈数据</param>
void Push(Stack* stack, struct Node* data);

/// <summary>
/// 弹栈
/// </summary>
/// <param name="stack">栈</param>
/// <returns>返回弹出的元素</returns>
struct Node* Pop(Stack* stack);

/// <summary>
/// 获取栈顶元素
/// </summary>
/// <param name="stack">栈</param>
/// <returns>返回栈顶元素</returns>
struct Node* Top(Stack* stack);

/// <summary>
/// 反向储存一个栈
/// </summary>
/// <param name="stack">栈</param>
/// <returns>返回逆序的栈</returns>
Stack* Reverse(Stack* stack);


/* Queue.cpp */

/// <summary>
/// 用两个栈模拟的队列结构
/// </summary>
struct Queue
{
    Stack* enqueueStack;
    Stack* dequeueStack;
};

/// <summary>
/// 初始化队列
/// </summary>
/// <returns>返回空队列</returns>
Queue* InitQueue();

/// <summary>
/// 查询队列是否为空
/// </summary>
/// <param name="queue">队列</param>
/// <returns>返回队列是否为空</returns>
bool IsEmpty(Queue* queue);

/// <summary>
/// 入队
/// </summary>
/// <param name="queue">队列</param>
/// <param name="data">待入队元素</param>
void Enqueue(Queue* queue, struct Node* data);

/// <summary>
/// 出队
/// </summary>
/// <param name="queue">队列</param>
/// <returns>返回出队元素</returns>
struct Node* Dequeue(Queue* queue);


/* Tree.cpp */

/**
 * \brief 树的最多节点个数
 */
#define MAX_NODE_COUNT 500

 /**
  * \brief 树中节点储存的数据类型
  */
typedef char elementType;

/// <summary>
/// 树的节点
/// </summary>
struct Node
{
    elementType data;
    struct Node* leftChild;
    struct Node* rightChild;
};

/**
 * \brief 树类型
 */
typedef Node* Tree;

/// <summary>
/// 用两个已有的树组成一个新树
/// </summary>
/// <param name="rootData">新树根节点数据</param>
/// <param name="leftTree">左子树</param>
/// <param name="rightTree">右子树</param>
/// <returns>返回新树</returns>
Tree Init(elementType rootData, Tree leftTree, Tree rightTree);

/// <summary>
/// 先序遍历，获取用户输入的树
/// </summary>
/// <returns>返回输入的树</returns>
Tree InputTree();

/// <summary>
/// 先序遍历树，非递归
/// </summary>
/// <param name="tree">树</param>
void PreOrderTravel(Tree tree);

/// <summary>
/// 先序遍历树，递归
/// </summary>
/// <param name="tree">树</param>
void PreOrderTravel_Recurse(Tree tree);

/// <summary>
/// 中序遍历树，非递归
/// </summary>
/// <param name="tree">树</param>
void InOrderTravel(Tree tree);

/// <summary>
/// 中序遍历树，递归
/// </summary>
/// <param name="tree">树</param>
void InOrderTravel_Recurse(Tree tree);

/// <summary>
/// 后序遍历树，非递归
/// </summary>
/// <param name="tree">树</param>
void PostOrderTravel(Tree tree);

/// <summary>
/// 后序遍历树，递归
/// </summary>
/// <param name="tree">树</param>
void PostOrderTravel_Recurse(Tree tree);

/// <summary>
/// 层序遍历树
/// </summary>
/// <param name="tree">树</param>
void LayerTravel(Tree tree);

/// <summary>
/// 判断二叉树是否为完全二叉树
/// </summary>
/// <param name="tree">二叉树</param>
/// <returns>返回是否为完全二叉树的结果</returns>
bool IsCompleteBinaryTree(Tree tree);

/// <summary>
/// 获取指定节点到根节点的路径
/// </summary>
/// <param name="tree">树</param>
/// <param name="node">节点</param>
/// <param name="nodePathToRoot">从指定节点到根的路径</param>
/// <param name="found">找到路径的标志，用于跳出递归</param>
void GetPathToRoot(Tree tree, Node* node, Stack* nodePathToRoot, bool* found);

/// <summary>
/// 获取两个节点的公共祖先
/// </summary>
/// <param name="tree">树</param>
/// <param name="node1">第一个节点</param>
/// <param name="node2">第二个节点</param>
/// <returns>返回两个节点的所有公共祖先</returns>
Node** GetPublicAncestors(Tree tree, Node* node1, Node* node2);

/// <summary>
/// 获取两个节点的公共祖先
/// </summary>
/// <param name="tree">树</param>
/// <param name="node1Data">第一个节点储存的数据</param>
/// <param name="node2Data">第二个节点储存的数据</param>
/// <returns>返回两个节点的所有公共祖先</returns>
Node** GetPublicAncestors(Tree tree, elementType node1Data, elementType node2Data);

/// <summary>
/// 根据数据寻找节点
/// </summary>
/// <param name="tree">树</param>
/// <param name="data">已知数据</param>
/// <returns>返回存储已知数据的节点</returns>
Node* FindNodeByData(Tree tree, elementType data);


/* Experiment.cpp */

/// <summary>
/// 测试实验一
/// </summary>
void TestExperiment1();
