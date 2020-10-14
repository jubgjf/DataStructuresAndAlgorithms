#pragma once


/* tb_tree.cpp */

/**
 * \brief 树节点储存的数据类型
 */
typedef char element_type;

/**
 * \brief 树节点
 */
struct node
{
    element_type data;

    struct node* l_child;
    bool l;

    struct node* r_child;
    bool r;
};

/**
 * \brief 树类型
 */
typedef struct node* tree;

/**
 * \brief 计算二叉树节点个数
 * \param b_tree 二叉树
 * \return 返回节点个数
 */
int size(tree b_tree);

/**
 * \brief 获取二叉树高度
 * \param b_tree 二叉树
 * \return 返回高度
 */
int height(tree b_tree);

/**
 * \brief 释放二叉树内存
 * \param b_tree 二叉树
 */
void destroy(tree b_tree);

/**
 * \brief 交换二叉树的所有节点子树（镜像对称）
 * \param b_tree 二叉树
 */
void mirror(tree b_tree);

/**
 * \brief 递归交换二叉树的所有节点子树（镜像对称）
 * \param b_tree 二叉树
 */
void mirror_r(tree b_tree);

/**
 * \brief 接受用户输入的二叉树
 * \return 返回输入的二叉树
 */
tree input();

/**
 * \brief 递归接受用户输入的二叉树
 * \return 返回输入的二叉树
 */
tree input_r();

/**
 * \brief 按照线索获取指定节点的后继节点
 * \param tb_tree 线索二叉树
 * \param node 指定节点
 * \return 返回后继节点
 */
node* tb_next(tree tb_tree, node* node);

/**
 * \brief 初始化线索
 */
void init();

/**
 * \brief 线索二叉树先序遍历
 * \param tb_tree 线索二叉树
 */
void pre_order(tree tb_tree);

/**
 * \brief 线索二叉树中序遍历
 * \param tb_tree 线索二叉树
 */
void in_order(tree tb_tree);

/**
 * \brief 层序遍历二叉树，遍历结果保存到数组中
 * \param b_tree 二叉树
 * \param list 遍历结果数组
 * \param index 遍历结果数组下标
 */
void layer(tree b_tree, node** list, int& index);

/**
 * \brief 在线索二叉树指定节点后插入节点
 * \param tb_tree 线索二叉树
 * \param position 插入位置
 * \param node 待插入的节点
 */
void insert(tree tb_tree, node* position, node* node);

/**
 * \brief 将层序遍历数组转换为二叉树
 * \param list 层序遍历数组
 * \param len 层序遍历数组长度
 * \return 返回转换后的二叉树
 */
tree list_to_tree(node** list, int len);

/**
 * \brief 复制二叉树
 * \param source 源二叉树
 * \return 返回副本二叉树
 */
tree copy(tree source);

/**
 * \brief 递归复制二叉树
 * \param source 源二叉树
 * \return 返回副本二叉树
 */
tree copy_r(tree source);

/**
 * \brief 判断二叉树是否相同
 * \param b_tree_1 第一个二叉树
 * \param b_tree_2 第二个二叉树
 * \return 返回是否相同的结果
 */
bool equal(tree b_tree_1, tree b_tree_2);
