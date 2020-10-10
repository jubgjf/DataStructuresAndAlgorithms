#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    Tree tree = InputTree();

    PreOrderTravel_Recurse(tree);
    cout << endl;
    PreOrderTravel(tree);
    cout << endl;
    InOrderTravel_Recurse(tree);
    cout << endl;
    PostOrderTravel_Recurse(tree);
    cout << endl;
    LayerTravel(tree);
    cout << endl;
    cout << IsCompleteBinaryTree(tree);
    cout << endl;
    Node** publicAncestors = GetPublicAncestors(tree,
                                                tree->leftChild->leftChild->leftChild,
                                                tree->leftChild->leftChild->rightChild);

    return 0;
}
