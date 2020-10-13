#pragma once


/* threaded_binary_tree.cpp */

/**
 * \brief 树节点储存的数据类型
 */
typedef char element_type;

/**
 * \brief 树节点
 */
struct tree_node
{
    element_type data;

    struct tree_node* left;
    bool is_left_child;

    struct tree_node* right;
    bool is_right_child;
};

/**
 * \brief 树类型
 */
typedef struct tree_node* tree;

/**
 * \brief 计算二叉树节点个数
 * \param binary_tree 二叉树
 * \return 返回节点个数
 */
int count_node(tree binary_tree);

/**
 * \brief 获取二叉树高度
 * \param binary_tree 二叉树
 * \return 返回高度
 */
int count_height(tree binary_tree);

/**
 * \brief 释放二叉树内存
 * \param binary_tree 二叉树
 */
void destroy(tree binary_tree);

/**
 * \brief 交换二叉树的所有节点子树（镜像对称）
 * \param binary_tree 二叉树
 */
void get_mirror(tree binary_tree);

/**
 * \brief 接受用户输入的二叉树
 * \return 返回输入的二叉树
 */
tree input_binary_tree();

/**
 * \brief 按照线索获取指定节点的后继节点
 * \param binary_tree 线索二叉树
 * \param node 指定节点
 * \return 返回后继节点
 */
tree_node* get_threaded_next(tree binary_tree, tree_node* node);

/**
 * \brief 初始化线索
 */
void init_threaded_binary_tree();

/**
 * \brief 线索二叉树先序遍历
 * \param binary_tree 线索二叉树
 */
void pre_order_travel(tree binary_tree);

/**
 * \brief 线索二叉树中序遍历
 * \param binary_tree 线索二叉树
 */
void in_order_travel(tree binary_tree);

/**
 * \brief 在线索二叉树指定节点后插入节点
 * \param binary_tree 线索二叉树
 * \param insert_position 插入位置
 * \param insert_node 待插入的节点
 */
void insert_node(tree binary_tree, tree_node* insert_position, tree_node* insert_node);

/**
 * \brief 复制二叉树
 * \param source_tree 源二叉树
 * \return 返回副本二叉树
 */
tree copy(tree source_tree);

/**
 * \brief 递归复制二叉树
 * \param source_tree 源二叉树
 * \return 返回副本二叉树
 */
tree copy_recurse(tree source_tree);

/**
 * \brief 判断二叉树是否相同
 * \param binary_tree_1 第一个二叉树
 * \param binary_tree_2 第二个二叉树
 * \return 返回是否相同的结果
 */
bool is_equal(tree binary_tree_1, tree binary_tree_2);
