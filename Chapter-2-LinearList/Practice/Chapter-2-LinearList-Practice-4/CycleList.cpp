#include "header.h"

node* InitList()
{
    // 环形链表用尾节点代表整个链表
    return nullptr;
}

void Insert(node* list, node* insertPosition, elementType data)
{
    node* insertNode = new node;
    insertNode->data = data;

    insertNode->next = insertPosition->next;
    insertPosition->next = insertNode;
}

node* LeftInsert(node* list, elementType data)
{
    node* insertNode = new node;
    insertNode->data = data;

    if (list != nullptr)
    {
        insertNode->next = list->next;
        list->next = insertNode;
    }
    else
    {
        list = insertNode;
        list->next = list;
    }

    return list;
}

void Delete(node* list, node* deletePosition)
{
    node* deleteNode = deletePosition->next;
    deletePosition->next = deleteNode->next;
    delete deleteNode;
}
