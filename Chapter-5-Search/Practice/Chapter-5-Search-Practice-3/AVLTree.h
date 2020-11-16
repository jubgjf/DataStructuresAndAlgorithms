#pragma once


/**
 * \brief 节点类型
 */
struct Node
{
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
};

/**
 * \brief 树类型
 */
typedef struct Node* Tree;

/**
 * \brief 初始化新树
 * \return 返回树
 */
Tree InitTree();

/**
 * \brief 获取树的高度
 * \param tree 树
 * \return 返回树的高度
 */
int GetHeight(Tree tree);

/**
 * \brief 向树中插入新数据，并检查插入后是否平衡
 * \param tree 树
 * \param data 待插入的数据
 */
void Insert(Tree tree, int data);

/**
 * \brief 不平衡的类型
 */
enum UnBalanceCase { Balance, RR, LL, RL, LR };

/**
 * \brief 检测树的不平衡类型
 * \param tree 树
 * \return 返回不平衡类型
 */
enum UnBalanceCase IdentifyUnBalanceCase(Tree tree);

/**
 * \brief 右旋
 * \param tree 树
 */
void RightRotate(Tree tree);

/**
 * \brief 左旋
 * \param tree 树
 */
void LeftRotate(Tree tree);

/**
 * \brief 处理RR不平衡类型
 * \param tree 树
 */
void MakeBalanceRR(Tree tree);

/**
 * \brief 处理LL不平衡类型
 * \param tree 树
 */
void MakeBalanceLL(Tree tree);

/**
 * \brief 处理RL不平衡类型
 * \param tree 树
 */
void MakeBalanceRL(Tree tree);

/**
 * \brief 处理LR不平衡类型
 * \param tree 树
 */
void MakeBalanceLR(Tree tree);
