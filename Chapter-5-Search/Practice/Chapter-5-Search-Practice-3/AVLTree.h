#pragma once


/**
 * \brief �ڵ�����
 */
struct Node
{
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
};

/**
 * \brief ������
 */
typedef struct Node* Tree;

/**
 * \brief ��ʼ������
 * \return ������
 */
Tree InitTree();

/**
 * \brief ��ȡ���ĸ߶�
 * \param tree ��
 * \return �������ĸ߶�
 */
int GetHeight(Tree tree);

/**
 * \brief �����в��������ݣ�����������Ƿ�ƽ��
 * \param tree ��
 * \param data �����������
 */
void Insert(Tree tree, int data);

/**
 * \brief ��ƽ�������
 */
enum UnBalanceCase { Balance, RR, LL, RL, LR };

/**
 * \brief ������Ĳ�ƽ������
 * \param tree ��
 * \return ���ز�ƽ������
 */
enum UnBalanceCase IdentifyUnBalanceCase(Tree tree);

/**
 * \brief ����
 * \param tree ��
 */
void RightRotate(Tree tree);

/**
 * \brief ����
 * \param tree ��
 */
void LeftRotate(Tree tree);

/**
 * \brief ����RR��ƽ������
 * \param tree ��
 */
void MakeBalanceRR(Tree tree);

/**
 * \brief ����LL��ƽ������
 * \param tree ��
 */
void MakeBalanceLL(Tree tree);

/**
 * \brief ����RL��ƽ������
 * \param tree ��
 */
void MakeBalanceRL(Tree tree);

/**
 * \brief ����LR��ƽ������
 * \param tree ��
 */
void MakeBalanceLR(Tree tree);
