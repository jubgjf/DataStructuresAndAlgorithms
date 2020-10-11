#pragma once

#include <string>
#include <vector>


/* Tree.cpp */

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
/// 获取根节点到指定节点的路径
/// </summary>
/// <param name="tree">树</param>
/// <param name="node">节点</param>
/// <param name="tempPath">递归时的临时路径</param>
/// <param name="finalPath">最终路径</param>
void GetPathFromRoot(Tree tree, Node* node, std::vector<Node*>& tempPath, std::vector<Node*>& finalPath);

/// <summary>
/// 获取两个节点的公共祖先
/// </summary>
/// <param name="tree">树</param>
/// <param name="node1">第一个节点</param>
/// <param name="node2">第二个节点</param>
/// <returns>返回两个节点的所有公共祖先</returns>
std::vector<Node*> GetPublicAncestors(Tree tree, Node* node1, Node* node2);

/// <summary>
/// 获取两个节点的公共祖先
/// </summary>
/// <param name="tree">树</param>
/// <param name="node1Data">第一个节点储存的数据</param>
/// <param name="node2Data">第二个节点储存的数据</param>
/// <returns>返回两个节点的所有公共祖先</returns>
std::vector<Node*> GetPublicAncestors(Tree tree, elementType node1Data, elementType node2Data);

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
