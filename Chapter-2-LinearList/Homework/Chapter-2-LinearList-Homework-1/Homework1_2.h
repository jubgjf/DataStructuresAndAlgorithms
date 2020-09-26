/// <summary>
/// ����������
/// </summary>
/// <param name="list">��Ҫ���õ�����</param>
inline void Reverse(cell* list)
{
    cell* pointer = list->next;

    if (pointer == nullptr) { return; }

    while (pointer->next != nullptr)
    {
        Insert(list, pointer->next->data);
        Delete(pointer, DELETE_BACK);
    }
}

/// <summary>
/// <para>������ҵ1.2������������������⡱
/// <para>������ú������
/// </summary>
/// <param name="count">����ڵ����</param>
/// <param name="...">����ĸ����ڵ������</param>
inline void TestHomework1_2(int count, ...)
{
    if (count == 0)
    {
        std::cout << "empty list" << std::endl;
        return;
    }

    va_list paraList;
    cell* list = InitList();
    cell* pointer = list;

    va_start(paraList, count);
    for (int i = 0; i < count; ++i)
    {
        pointer = Insert(pointer, va_arg(paraList, elementType));
    }
    va_end(paraList);

    Reverse(list);

    Travel(list);
}
