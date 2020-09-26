//
// @brief: ��̬������ϰ
//

#include <iostream>


/// <summary>
/// ��̬������󳤶�
/// </summary>
constexpr int maxLength = 10;

/// <summary>
/// �����е���������
/// </summary>
typedef int elementType;

/// <summary>
/// ��̬�����һ���ڵ�
/// </summary>
struct StaticList
{
    elementType data;
    int next;
};

/// <summary>
/// ��ʼ���洢��
/// </summary>
/// <param name="avail">����λ�����</param>
/// <returns>���ش洢��</returns>
StaticList* InitSpace(int* avail)
{
    *avail = 0;

    StaticList space[maxLength];

    for (int i = 0; i < maxLength - 1; ++i)
    {
        space[i].next = i + 1;
    }
    space[maxLength - 1].next = -1;

    return space;
}

/// <summary>
/// �Ӵ洢�������¾�̬����
/// </summary>
/// <param name="space">�洢��</param>
/// <param name="avail">����λ�����</param>
/// <returns>��������ͷ�ڵ����</returns>
int NewList(StaticList* space, int* avail)
{
    // TODO ����NewList

    int listHead = *avail;
    *avail = space[listHead].next;
    space[listHead].next = -1;

    return listHead;
}

/// <summary>
/// ��̬����ָ��λ�ú�߲���ڵ�
/// </summary>
/// <param name="space">�洢��</param>
/// <param name="avail">����λ�����</param>
/// <param name="insertPosition">�����½ڵ��λ��</param>
/// <param name="data">�½ڵ�����</param>
/// <returns>�����½ڵ��Ӧ���</returns>
int Insert(StaticList* space, int* avail, int insertPosition, elementType data)
{
    // TODO ����Insert

    int insertIndex = *avail;

    space[insertIndex].data = data;
    *avail = space[insertIndex].next;
    space[insertIndex].next = space[insertPosition].next;
    space[insertPosition].next = insertIndex;

    return insertIndex;
}

/// <summary>
/// ɾ����̬����ָ���ڵ��ߵĽڵ�
/// </summary>
/// <param name="space">�洢��</param>
/// <param name="avail">����λ�����</param>
/// <param name="deletePosition">ɾ���ڵ��λ��</param>
void Delete(StaticList* space, int* avail, int deletePosition)
{
    // TODO ����Delete

    int deleteIndex = space[deletePosition].next;

    space[deletePosition].next = space[deleteIndex].next;
    space[deleteIndex].next = *avail;
    *avail = deleteIndex;
}

/// <summary>
/// �����̬��������Ԫ����Ϣ
/// </summary>
/// <param name="space">�洢��</param>
/// <param name="listHead">����ͷ�ڵ����</param>
void Travel(StaticList* space, int listHead)
{
    // TODO ����Travel

    StaticList node = space[listHead];

    while (node.next != -1)
    {
        std::cout << node.data << std::endl;
    }
    std::cout << node.data << std::endl;
}

int main()
{
    int avail;
    StaticList* space = InitSpace(&avail);

    int listHead = NewList(space, &avail);

    Insert(space, &avail, listHead, 9);
}
