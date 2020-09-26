//
// ½øÖÆ×ª»»Á·Ï°
//

#include <iostream>
#include "../Chapter-2-LinearList-Practice-2/BasicOperations.h"

using namespace std;

int main()
{
    node* stack = InitStack();
    int num;
    cin >> num;

    while (num != 0)
    {
        Push(stack, num % 2);
        num /= 2;
    }

    while (Top(stack) != -1)
    {
        cout << Pop(stack);
    }
}
