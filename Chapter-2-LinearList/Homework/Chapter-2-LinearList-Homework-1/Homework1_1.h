#include <cstdarg>

/// <summary>
/// �������У����ҵ�����k���ڵ��е�����
/// </summary>
/// <param name="list">�����ҵ�����</param>
/// <param name="index">������index���ڵ㣨��0��ʼ���㣩</param>
/// <returns>���ҳɹ��򷵻ظýڵ㣬���򷵻�nullptr</returns>
inline cell* RetrieveByReverse(cell* list, int index)
{
    cell* frontCell = list->next;
    cell* backCell = list->next;

    if (backCell == nullptr) { return nullptr; }

    for (int i = 0; i < index; i++)
    {
        if (backCell->next != nullptr)
        {
            backCell = backCell->next;
        }
        else
        {
            return nullptr;
        }
    }
    while (backCell->next != nullptr)
    {
        frontCell = frontCell->next;
        backCell = backCell->next;
    }

    return frontCell;
}

/// <summary>
/// ���������м�ڵ������
/// </summary>
enum MIDDLE_TYPE
{
    MIDDLE_FRONT,
    MIDDLE_BACK
};

/// <summary>
/// �������У������м�ڵ�
/// </summary>
/// <param name="list">�����ҵ�����</param>
/// <param name="middleType">����ż�����ڵ�Ĵ���ʽ</param>
/// <returns>
/// <para>�����������ڵ㣬�򷵻����м�Ľڵ㣻
/// <para>����ż�����ڵ㣬��MIDDLE_TYPEΪMIDDLE_FRONT���򷵻��м�������ǰһ���ڵ㣨Ĭ�ϣ�
/// <para>����ż�����ڵ㣬��MIDDLE_TYPEΪMIDDLE_BACK���򷵻��м������ĺ�һ���ڵ�
/// <para>��Ϊ�������򷵻�nullptr
/// </returns>
inline cell* RetrieveMiddle(cell* list, enum MIDDLE_TYPE middleType = MIDDLE_FRONT)
{
    cell* frontCell = list->next;
    cell* backCell = list->next;

    if (backCell == nullptr) { return nullptr; }

    switch (middleType)
    {
    case MIDDLE_FRONT:
        while (backCell->next != nullptr && backCell->next->next != nullptr)
        {
            frontCell = frontCell->next;
            backCell = backCell->next->next;
        }
        break;
    case MIDDLE_BACK:
        while (backCell != nullptr && backCell->next != nullptr)
        {
            frontCell = frontCell->next;
            backCell = backCell->next->next;
        }
        break;
    }

    return frontCell;
}

/// <summary>
/// <para>������ҵ1.1.1��������������k��Ԫ�ء�
/// <para>���������k���ڵ�����ݣ��������ڸýڵ㣬�����"index k not found"
/// </summary>
/// <param name="count">����ڵ����</param>
/// <param name="k">��Ҫ����������ڼ����ڵ�</param>
/// <param name="...">����ĸ����ڵ������</param>
inline void TestHomework1_1_1(int count, int k, ...)
{
    va_list paraList;
    cell* list = InitList();
    cell* pointer = list;

    va_start(paraList, k);
    for (int i = 0; i < count; ++i)
    {
        pointer = Insert(pointer, va_arg(paraList, elementType));
    }
    va_end(paraList);

    cell* resultCell = RetrieveByReverse(list, k);

    if (resultCell == nullptr) { std::cout << "index k not found" << std::endl; }
    else { std::cout << resultCell->data << std::endl; }
}

/// <summary>
/// <para>������ҵ1.1.2�����������е�Ԫ�ء�
/// <para>����м�ڵ�����ݣ��������ڸýڵ㣬�����"empty list"
/// </summary>
/// <param name="count">����ڵ����</param>
/// <param name="middleType">��������ż�����ڵ�ʱ��ѡȡ��һ��ȡ�е㷽ʽ</param>
/// <param name="...">����ĸ����ڵ������</param>
inline void TestHomework1_1_2(int count, enum MIDDLE_TYPE middleType, ...)
{
    va_list paraList;
    cell* list = InitList();
    cell* pointer = list;

    va_start(paraList, middleType);
    for (int i = 0; i < count; ++i)
    {
        pointer = Insert(pointer, va_arg(paraList, elementType));
    }
    va_end(paraList);

    cell* resultCell = RetrieveMiddle(list, middleType);

    if (resultCell == nullptr) { std::cout << "empty list" << std::endl; }
    else { std::cout << resultCell->data << std::endl; }
}
