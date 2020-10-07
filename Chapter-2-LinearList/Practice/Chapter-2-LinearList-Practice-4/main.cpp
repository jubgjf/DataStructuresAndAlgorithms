#include "header.h"

int main()
{
    node* list = InitList();

    list = LeftInsert(list, 1);
    list = LeftInsert(list, 2);
    list = LeftInsert(list, 3);

    Insert(list, list->next->next, 4);

    Delete(list, list->next);
}
