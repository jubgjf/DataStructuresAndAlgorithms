#include <iostream>
#include <stack>
#include "header.h"

using namespace std;

Tree Init(elementType rootData, Tree leftTree, Tree rightTree)
{
    node* rootNode = new node;
    rootNode->data = rootData;
    rootNode->leftChild = leftTree;
    rootNode->rightChild = rightTree;

    return rootNode;
}

Tree InputTree()
{
    Tree tree = new node;

    elementType c;
    cin >> c;
    switch (c)
    {
    case '#':
        return nullptr;
    default:
        tree->data = c;
        tree->leftChild = InputTree();
        tree->rightChild = InputTree();
        return tree;
    }
}

void PreOrderTravel(Tree tree)
{   
}

void PreOrderTravel_Recurse(Tree tree)
{
    if (tree == nullptr) { return; }

    cout << tree->data;
    PreOrderTravel_Recurse(tree->leftChild);
    PreOrderTravel_Recurse(tree->rightChild);
}

void InOrderTravel(Tree tree)
{
}

void InOrderTravel_Recurse(Tree tree)
{
    if (tree == nullptr) { return; }

    InOrderTravel_Recurse(tree->leftChild);
    cout << tree->data;
    InOrderTravel_Recurse(tree->rightChild);
}

void PostOrderTravel(Tree tree)
{
}

void PostOrderTravel_Recurse(Tree tree)
{
    if (tree == nullptr) { return; }

    PostOrderTravel_Recurse(tree->leftChild);
    PostOrderTravel_Recurse(tree->rightChild);
    cout << tree->data;
}

void LayerTravel(Tree tree)
{
}

bool IsBinaryTree(Tree tree)
{
    return false;
}

node* GetPublicAncestor(Tree tree, node* node1, node* node2)
{
    return nullptr;
}
