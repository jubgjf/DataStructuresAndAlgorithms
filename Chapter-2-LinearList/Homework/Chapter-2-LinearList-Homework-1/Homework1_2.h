/// <summary>
/// 将链表逆置
/// </summary>
/// <param name="list">需要逆置的链表</param>
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
/// <para>测试作业1.2：“单链表的逆置问题”
/// <para>输出逆置后的链表
/// </summary>
/// <param name="count">链表节点个数</param>
/// <param name="...">链表的各个节点的数据</param>
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
