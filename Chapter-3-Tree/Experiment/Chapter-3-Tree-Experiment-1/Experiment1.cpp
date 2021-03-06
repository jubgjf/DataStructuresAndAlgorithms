﻿#include <iostream>
#include "header.h"

using namespace std;

void TestExperiment1()
{
    cout << "input your tree in pre order:\t";
    Tree tree = InputTree();

    // 课件用例：ABDH##I##E##CF#J##G##

    cout << "pre order travel without recurse:\t";
    PreOrderTravel(tree);
    cout << endl;

    cout << "pre order travel with    recurse:\t";
    PreOrderTravel_Recurse(tree);
    cout << endl;

    cout << "in order travel without recurse:\t";
    InOrderTravel(tree);
    cout << endl;

    cout << "in order travel with    recurse:\t";
    InOrderTravel_Recurse(tree);
    cout << endl;

    cout << "post order travel without recurse:\t";
    PostOrderTravel(tree);
    cout << endl;

    cout << "post order travel with    recurse:\t";
    PostOrderTravel_Recurse(tree);
    cout << endl;

    cout << "layer travel with recurse:\t";
    LayerTravel(tree);
    cout << endl;

    IsCompleteBinaryTree(tree) ? cout << "this is a binary tree" : cout << "not a binary tree";
    cout << endl;

    elementType node1Data, node2Data;
    cout << "input 2 nodes to find public ancestors:\t";
    cin >> node1Data >> node2Data;
    Node** publicAncestors = GetPublicAncestors(tree, node1Data, node2Data);
    if (publicAncestors[0] == nullptr)
    {
        cout << "no public ancestor, check your input";
    }
    else
    {
        for (int i = 0; publicAncestors[i] != nullptr; ++i)
        {
            cout << publicAncestors[i]->data;
        }
    }
}
