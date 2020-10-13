#pragma once


/* threaded_binary_tree.cpp */

/**
 * \brief ���ڵ㴢�����������
 */
typedef char element_type;

/**
 * \brief ���ڵ�
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
 * \brief ������
 */
typedef struct tree_node* tree;

/**
 * \brief ����������ڵ����
 * \param binary_tree ������
 * \return ���ؽڵ����
 */
int count_node(tree binary_tree);

/**
 * \brief ��ȡ�������߶�
 * \param binary_tree ������
 * \return ���ظ߶�
 */
int count_height(tree binary_tree);

/**
 * \brief �ͷŶ������ڴ�
 * \param binary_tree ������
 */
void destroy(tree binary_tree);

/**
 * \brief ���������������нڵ�����������Գƣ�
 * \param binary_tree ������
 */
void get_mirror(tree binary_tree);

/**
 * \brief �����û�����Ķ�����
 * \return ��������Ķ�����
 */
tree input_binary_tree();

/**
 * \brief ����������ȡָ���ڵ�ĺ�̽ڵ�
 * \param binary_tree ����������
 * \param node ָ���ڵ�
 * \return ���غ�̽ڵ�
 */
tree_node* get_threaded_next(tree binary_tree, tree_node* node);

/**
 * \brief ��ʼ������
 */
void init_threaded_binary_tree();

/**
 * \brief �����������������
 * \param binary_tree ����������
 */
void pre_order_travel(tree binary_tree);

/**
 * \brief �����������������
 * \param binary_tree ����������
 */
void in_order_travel(tree binary_tree);

/**
 * \brief ������������ָ���ڵ�����ڵ�
 * \param binary_tree ����������
 * \param insert_position ����λ��
 * \param insert_node ������Ľڵ�
 */
void insert_node(tree binary_tree, tree_node* insert_position, tree_node* insert_node);

/**
 * \brief ���ƶ�����
 * \param source_tree Դ������
 * \return ���ظ���������
 */
tree copy(tree source_tree);

/**
 * \brief �ݹ鸴�ƶ�����
 * \param source_tree Դ������
 * \return ���ظ���������
 */
tree copy_recurse(tree source_tree);

/**
 * \brief �ж϶������Ƿ���ͬ
 * \param binary_tree_1 ��һ��������
 * \param binary_tree_2 �ڶ���������
 * \return �����Ƿ���ͬ�Ľ��
 */
bool is_equal(tree binary_tree_1, tree binary_tree_2);
