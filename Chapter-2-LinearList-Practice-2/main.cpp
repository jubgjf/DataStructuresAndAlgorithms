//
// @brief: Õ»Á·Ï°
//

#include "BasicOperations.h"

int main()
{
    node* stack = InitStack();

    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);
    Push(stack, 4);

    Pop(stack);
    Pop(stack);

    Push(stack, 5);

    Pop(stack);

    Top(stack);

    Empty(stack);

    return 0;
}
