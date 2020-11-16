#include "AVLTree.h"

Tree InitTree()
{
    Tree tree = new Node;
    tree->data = 0;
    tree->leftChild = nullptr;
    tree->rightChild = nullptr;

    return tree;
}

int GetHeight(Tree tree)
{
    return 0;
}

void Insert(Tree tree, int data)
{
    // Insert TODO

    switch (IdentifyUnBalanceCase(tree))
    {
    case Balance:
        break;
    case RR:
        MakeBalanceRR(tree);
        break;
    case LL:
        MakeBalanceLL(tree);
        break;
    case RL:
        MakeBalanceRL(tree);
        break;
    case LR:
        MakeBalanceLR(tree);
        break;
    }
}

UnBalanceCase IdentifyUnBalanceCase(Tree tree)
{
    return Balance;
}

void RightRotate(Tree tree)
{
}

void LeftRotate(Tree tree)
{
}

void MakeBalanceRR(Tree tree)
{
}

void MakeBalanceLL(Tree tree)
{
}

void MakeBalanceRL(Tree tree)
{
}

void MakeBalanceLR(Tree tree)
{
}
