#include <iostream>
#include "header.h"

using namespace std;

Tree Init(elementType rootData, Tree leftTree, Tree rightTree)
{
    Node* rootNode = new Node;
    rootNode->data = rootData;
    rootNode->leftChild = leftTree;
    rootNode->rightChild = rightTree;

    return rootNode;
}

Tree InputTree()
{
    Tree tree = new Node;

    elementType c;
    cin >> c;

    if (c == '#') { return nullptr; }

    tree->data = c;
    tree->leftChild = InputTree();
    tree->rightChild = InputTree();

    return tree;
}

void PreOrderTravel(Tree tree)
{
    // 对于任一结点P：
    // 1. 访问结点P，并将结点P入栈
    // 2. 判断结点P的左孩子是否为空，若为空，则取栈顶结点并进行出栈操作，并将栈顶结点的右孩子置为当前的结点P，循环至1
    // 若不为空，则将P的左孩子置为当前的结点P
    // 3. 直到P为NULL并且栈为空，则遍历结束

    Stack* nodeStack = InitStack();
    Node* node = tree;

    while (node != nullptr || !IsEmpty(nodeStack))
    {
        while (node != nullptr)
        {
            cout << node->data;
            Push(nodeStack, node);
            node = node->leftChild;
        }
        if (!IsEmpty(nodeStack))
        {
            node = Pop(nodeStack);
            node = node->rightChild;
        }
    }
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
    Stack* nodeStack = InitStack();
    Node* node = tree;

    while (node != nullptr || !IsEmpty(nodeStack))
    {
        while (node != nullptr)
        {
            Push(nodeStack, node);
            node = node->leftChild;
        }
        if (!IsEmpty(nodeStack))
        {
            node = Pop(nodeStack);
            cout << node->data;
            node = node->rightChild;
        }
    }
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
    // 前序遍历为：根->左->右，后序遍历为：左->右->根
    // 只需类似前序遍历，记录“根->右->左”，再进行逆序，便得到左->右->根

    Stack* nodeStack = InitStack();
    Stack* reverseStack = InitStack();
    Node* node = tree;

    while (node != nullptr || !IsEmpty(nodeStack))
    {
        while (node != nullptr)
        {
            Push(reverseStack, node);
            Push(nodeStack, node);
            node = node->rightChild;
        }
        if (!IsEmpty(nodeStack))
        {
            node = Pop(nodeStack);
            node = node->leftChild;
        }
    }

    while (!IsEmpty(reverseStack))
    {
        cout << Pop(reverseStack)->data;
    }
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
    Queue* nodeQueue = InitQueue();

    Enqueue(nodeQueue, tree);

    while (!IsEmpty(nodeQueue))
    {
        Node* node = Dequeue(nodeQueue);
        cout << node->data;
        if (node->leftChild != nullptr) { Enqueue(nodeQueue, node->leftChild); }
        if (node->rightChild != nullptr) { Enqueue(nodeQueue, node->rightChild); }
    }
}

bool IsCompleteBinaryTree(Tree tree)
{
    // 层序遍历，如果队列不为空，一直循环
    // 遇到第一个没有左孩子或者右孩子的结点，设置标记位 = true
    // 继续入队，如果再次遇到存在孩子的结点，一定不是完全二叉树

    Queue* nodeQueue = InitQueue();

    bool result = false;

    Enqueue(nodeQueue, tree);

    while (!IsEmpty(nodeQueue))
    {
        Node* node = Dequeue(nodeQueue);

        if (node->leftChild == nullptr && node->rightChild == nullptr)
        {
            result = true;
        }
        else if (node->leftChild == nullptr && node->rightChild != nullptr)
        {
            return false;
        }
        else if (node->leftChild != nullptr && node->rightChild == nullptr)
        {
            if (result == true) { return false; }
            Enqueue(nodeQueue, node->leftChild);
        }
        else if (node->leftChild != nullptr && node->rightChild != nullptr)
        {
            if (result == true) { return false; }
            Enqueue(nodeQueue, node->leftChild);
            Enqueue(nodeQueue, node->rightChild);
        }
    }

    return true;
}

void GetPathFromRoot(Tree tree, Node* node, vector<Node*>& tempPath, vector<Node*>& finalPath)
{
    if (tree == nullptr) { return; }

    tempPath.push_back(tree);

    if (tree == node)
    {
        finalPath = tempPath;
        return;
    }

    if (tree->leftChild != nullptr) { GetPathFromRoot(tree->leftChild, node, tempPath, finalPath); }
    if (tree->rightChild != nullptr) { GetPathFromRoot(tree->rightChild, node, tempPath, finalPath); }

    tempPath.pop_back();
}

vector<Node*> GetPublicAncestors(Tree tree, Node* node1, Node* node2)
{
    vector<Node*> node1PathToRoot, node2PathToRoot;
    vector<Node*> tempPath1, tempPath2;
    vector<Node*> publicAncestors;

    GetPathFromRoot(tree, node1, tempPath1, node1PathToRoot);
    GetPathFromRoot(tree, node2, tempPath2, node2PathToRoot);

    for (unsigned i = 0; i < node1PathToRoot.size(); ++i)
    {
        for (unsigned j = 0; j < node2PathToRoot.size(); ++j)
        {
            if (node1PathToRoot[i] == node2PathToRoot[j])
            {
                publicAncestors.push_back(node1PathToRoot[i]);
            }
        }
    }

    return publicAncestors;
}

vector<Node*> GetPublicAncestors(Tree tree, elementType node1Data, elementType node2Data)
{
    Node* node1 = FindNodeByData(tree, node1Data);
    Node* node2 = FindNodeByData(tree, node2Data);

    return GetPublicAncestors(tree, node1, node2);
}

Node* FindNodeByData(Tree tree, elementType data)
{
    Stack* nodeStack = InitStack();
    Node* node = tree;

    // 先序遍历
    while (node != nullptr || !IsEmpty(nodeStack))
    {
        while (node != nullptr)
        {
            if (node->data == data) { return node; }
            Push(nodeStack, node);
            node = node->leftChild;
        }
        if (!IsEmpty(nodeStack))
        {
            node = Pop(nodeStack);
            node = node->rightChild;
        }
    }

    return nullptr;
}
