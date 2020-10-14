#pragma once


/* tb_tree.cpp */

/**
 * \brief ���ڵ㴢�����������
 */
typedef char element_type;

/**
 * \brief ���ڵ�
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
 * \brief ������
 */
typedef struct node* tree;

/**
 * \brief ����������ڵ����
 * \param b_tree ������
 * \return ���ؽڵ����
 */
int size(tree b_tree);

/**
 * \brief ��ȡ�������߶�
 * \param b_tree ������
 * \return ���ظ߶�
 */
int height(tree b_tree);

/**
 * \brief �ͷŶ������ڴ�
 * \param b_tree ������
 */
void destroy(tree b_tree);

/**
 * \brief ���������������нڵ�����������Գƣ�
 * \param b_tree ������
 */
void mirror(tree b_tree);

/**
 * \brief �ݹ齻�������������нڵ�����������Գƣ�
 * \param b_tree ������
 */
void mirror_r(tree b_tree);

/**
 * \brief �����û�����Ķ�����
 * \return ��������Ķ�����
 */
tree input();

/**
 * \brief �ݹ�����û�����Ķ�����
 * \return ��������Ķ�����
 */
tree input_r();

/**
 * \brief ����������ȡָ���ڵ�ĺ�̽ڵ�
 * \param tb_tree ����������
 * \param node ָ���ڵ�
 * \return ���غ�̽ڵ�
 */
node* tb_next(tree tb_tree, node* node);

/**
 * \brief ��ʼ������
 */
void init();

/**
 * \brief �����������������
 * \param tb_tree ����������
 */
void pre_order(tree tb_tree);

/**
 * \brief �����������������
 * \param tb_tree ����������
 */
void in_order(tree tb_tree);

/**
 * \brief �������������������������浽������
 * \param b_tree ������
 * \param list �����������
 * \param index ������������±�
 */
void layer(tree b_tree, node** list, int& index);

/**
 * \brief ������������ָ���ڵ�����ڵ�
 * \param tb_tree ����������
 * \param position ����λ��
 * \param node ������Ľڵ�
 */
void insert(tree tb_tree, node* position, node* node);

/**
 * \brief �������������ת��Ϊ������
 * \param list �����������
 * \param len ����������鳤��
 * \return ����ת����Ķ�����
 */
tree list_to_tree(node** list, int len);

/**
 * \brief ���ƶ�����
 * \param source Դ������
 * \return ���ظ���������
 */
tree copy(tree source);

/**
 * \brief �ݹ鸴�ƶ�����
 * \param source Դ������
 * \return ���ظ���������
 */
tree copy_r(tree source);

/**
 * \brief �ж϶������Ƿ���ͬ
 * \param b_tree_1 ��һ��������
 * \param b_tree_2 �ڶ���������
 * \return �����Ƿ���ͬ�Ľ��
 */
bool equal(tree b_tree_1, tree b_tree_2);
