#pragma once

/**
 * \brief 树中节点储存的数据类型
 */
typedef char elementType;

/// <summary>
/// 树的节点
/// </summary>
struct node
{
    elementType data;
    struct node* leftChild;
    struct node* rightChild;
};

/**
 * \brief 树类型
 */
typedef node* Tree;

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
/// 判断树是否为二叉树
/// </summary>
/// <param name="tree">树</param>
/// <returns>返回是否为二叉树的结果</returns>
bool IsBinaryTree(Tree tree);

/// <summary>
/// 获取两个节点的公共祖先
/// </summary>
/// <param name="tree">树</param>
/// <param name="node1">第一个节点</param>
/// <param name="node2">第二个节点</param>
/// <returns>返回两个节点的第一个公共祖先</returns>
node* GetPublicAncestor(Tree tree, node* node1, node* node2);
