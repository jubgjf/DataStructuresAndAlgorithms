#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    Tree tree = InputTree();

    PreOrderTravel_Recurse(tree);
    cout << endl;
    InOrderTravel_Recurse(tree);
    cout << endl;
    PostOrderTravel_Recurse(tree);
    cout << endl;

    return 0;
}
