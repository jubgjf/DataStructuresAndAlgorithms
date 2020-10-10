#include <iostream>
#include <queue>
#include <stack>
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
    // 对于任一结点P：
    // 1. 访问结点P，并将结点P入栈
    // 2. 判断结点P的左孩子是否为空，若为空，则取栈顶结点并进行出栈操作，并将栈顶结点的右孩子置为当前的结点P，循环至1
    // 若不为空，则将P的左孩子置为当前的结点P
    // 3. 直到P为NULL并且栈为空，则遍历结束

    stack<Tree> nodeStack;
    Node* node = tree;

    while (node != nullptr || !nodeStack.empty())
    {
        while (node != nullptr)
        {
            cout << node->data;
            nodeStack.push(node);
            node = node->leftChild;
        }
        if (!nodeStack.empty())
        {
            node = nodeStack.top();
            nodeStack.pop();
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
    stack<Tree> nodeStack;
    Node* node = tree;

    while (node != nullptr || !nodeStack.empty())
    {
        while (node != nullptr)
        {
            nodeStack.push(node);
            node = node->leftChild;
        }
        if (!nodeStack.empty())
        {
            node = nodeStack.top();
            cout << node->data;
            nodeStack.pop();
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
    queue<Tree> nodeQueue;

    nodeQueue.push(tree);

    while (!nodeQueue.empty())
    {
        Node* node = nodeQueue.front();
        cout << node->data;
        nodeQueue.pop();
        if (node->leftChild != nullptr) { nodeQueue.push(node->leftChild); }
        if (node->rightChild != nullptr) { nodeQueue.push(node->rightChild); }
    }
}

bool IsCompleteBinaryTree(Tree tree)
{
    // 层序遍历，如果队列不为空，一直循环
    // 遇到第一个没有左孩子或者右孩子的结点，设置标记位 = true
    // 继续入队，如果再次遇到存在孩子的结点，一定不是完全二叉树

    queue<Tree> nodeQueue;

    bool result = false;

    nodeQueue.push(tree);

    while (!nodeQueue.empty())
    {
        Node* node = nodeQueue.front();
        nodeQueue.pop();

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
            nodeQueue.push(node->leftChild);
        }
        else if (node->leftChild != nullptr && node->rightChild != nullptr)
        {
            if (result == true) { return false; }
            nodeQueue.push(node->leftChild);
            nodeQueue.push(node->rightChild);
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

Node** GetPublicAncestors(Tree tree, Node* node1, Node* node2)
{
    vector<Node*> node1PathToRoot, node2PathToRoot;
    vector<Node*> tempPath1, tempPath2;
    vector<Node*> publicAncestorsVector;

    GetPathFromRoot(tree, node1, tempPath1, node1PathToRoot);
    GetPathFromRoot(tree, node2, tempPath2, node2PathToRoot);

    for (int i = 0; i < node1PathToRoot.size(); ++i)
    {
        for (int j = 0; j < node2PathToRoot.size(); ++j)
        {
            if (node1PathToRoot[i] == node2PathToRoot[j])
            {
                publicAncestorsVector.push_back(node1PathToRoot[i]);
            }
        }
    }

    Node** publicAncestors = static_cast<Node**>(malloc(publicAncestorsVector.size()));
    for (int i = 0; i < publicAncestorsVector.size(); ++i)
    {
        publicAncestors[i] = publicAncestorsVector[i];
    }

    return publicAncestors;
}
