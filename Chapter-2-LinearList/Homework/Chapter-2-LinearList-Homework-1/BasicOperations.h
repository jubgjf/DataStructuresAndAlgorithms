#include <iostream>
#include <cstdlib>

/// <summary>
/// ����ڵ������ݵ�����
/// </summary>
typedef int elementType;

/// <summary>
/// �����һ���ڵ�
/// </summary>
struct cell
{
    elementType data;
    struct cell* next;
};

/// <summary>
/// ����һ��������
/// </summary>
/// <returns>����ͷ�ڵ�</returns>
inline cell* InitList()
{
    cell* head = (cell*)malloc(sizeof(cell));
    head->data = 0; // ͷ�ڵ��е���������Ϊ0
    head->next = nullptr;
    return head;
}

/// <summary>
/// ����ڵ����
/// </summary>
enum INSERT_TYPE
{
    INSERT_FRONT,
    INSERT_BACK
};

/// <summary>
/// ��������ָ��λ�ò���һ���ڵ�
/// </summary>
/// <param name="insertPosition">�������λ��</param>
/// <param name="insertData">�����������</param>
/// <param name="insertType">
/// <para>��ΪINSERT_FRONT�����������insertPosition�ڵ�ǰ������һ������Ϊdata�Ľڵ�
/// <para>��ΪINSERT_BACK�����������insertPosition�ڵ�󣬲���һ������Ϊdata�Ľڵ㣨Ĭ�ϣ�
/// </param>
/// <returns>����ɹ��򷵻ر�����Ľڵ㣬���򷵻�nullptr</returns>
inline cell* Insert(cell* insertPosition, elementType insertData, enum INSERT_TYPE insertType = INSERT_BACK)
{
    cell* insertCell = (cell*)malloc(sizeof(cell));
    if (insertCell == nullptr) { return nullptr; }

    insertCell->data = insertData;

    switch (insertType)
    {
    case INSERT_FRONT:
        // TODO δ��� INSERT_FRONT
        break;
    case INSERT_BACK:
        insertCell->next = insertPosition->next;
        insertPosition->next = insertCell;
        break;
    }

    return insertCell;
}

/// <summary>
/// ɾ���ڵ����
/// </summary>
enum DELETE_TYPE
{
    DELETE_FRONT,
    DELETE_HERE,
    DELETE_BACK
};

/// <summary>
/// ��������ָ��λ��ɾ���ڵ�
/// </summary>
/// <param name="deletePosition">��ɾ����λ��</param>
/// <param name="deleteType">
/// <para>��ΪDELETE_FRONT����ɾ��deletePosition�ڵ�ǰ�ߵĽڵ�
/// <para>��ΪDELETE_HERE����ɾ��deletePosition�ڵ㣨Ĭ�ϣ�
/// <para>��ΪDELETE_BACK����ɾ��deletePosition�ڵ��ߵĽڵ�
/// </param>
/// <returns>ɾ���ɹ��򷵻ر�ɾ���ڵ�ǰ�ߵĽڵ㣬���򷵻�nullptr</returns>
inline cell* Delete(cell* deletePosition, enum DELETE_TYPE deleteType = DELETE_HERE)
{
    switch (deleteType)
    {
    case DELETE_FRONT:
        // TODO δ��� DELETE_FRONT
        break;
    case DELETE_HERE:
        // TODO δ��� DELETE_HERE
        break;
    case DELETE_BACK:
        if (deletePosition->next != nullptr)
        {
            cell* tempCell = deletePosition->next;
            deletePosition->next = tempCell->next;
            free(tempCell);

            return deletePosition;
        }
        return nullptr;
    }

    return nullptr;
}

/// <summary>
/// �������У�Ѱ��ĳ����һ�γ��ֵ�λ��
/// </summary>
/// <param name="list">�����ҵ�����</param>
/// <param name="dataToFind">�����ҵ�����</param>
/// <returns>���ҵ��򷵻ص�һ�γ������ڵĽڵ㣬���򷵻�nullptr</returns>
inline cell* Locate(cell* list, elementType dataToFind)
{
    cell* pointer = list->next;
    while (pointer != nullptr)
    {
        if (pointer->data == dataToFind)
        {
            return pointer;
        }
        else
        {
            pointer = pointer->next;
        }
    }

    return nullptr;
}

/// <summary>
/// ������������������ڵ�����
/// </summary>
/// <param name="list">������������</param>
inline void Travel(cell* list)
{
    cell* pointer = list->next;

    while (pointer != nullptr)
    {
        std::cout << pointer->data << " ";
        pointer = pointer->next;
    }
    std::cout << std::endl;
}
