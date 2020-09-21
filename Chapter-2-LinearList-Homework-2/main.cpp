#include "BasicOperations.h"
#include "FileIO.h"

int main()
{
    Cell* list = InitList();
    Insert(list,
           {"headphone", "Sony", 1899, 10});
    Insert(list->next,
           {"laptop", "Apple", 23000, 5});
    Insert(list->next->next,
           {"water", "Farmer's_Spring", 2, 1000});
    Insert(list->next->next->next,
           {"computer", "Dell", 13999, 10});


    WriteDataToFile(list->next->data, OVERWRITE);
    WriteDataToFile(list->next->next->data);
    WriteDataToFile(list->next->next->next->data);
    WriteDataToFile(list->next->next->next->next->data);

    Cell* l = ReadListFromFile();

    return 0;
}
