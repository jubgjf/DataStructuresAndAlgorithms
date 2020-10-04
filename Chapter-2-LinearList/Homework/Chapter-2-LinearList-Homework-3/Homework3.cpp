#include <iostream>
#include "header.h"

using namespace std;

void TestHomework3()
{
    int width, height;
    Position startPosition, endPosition;
    node* stack = InitStack();


    cout << "input maze width:\t";
    cin >> width;
    cout << "input maze height:\t";
    cin >> height;
    cout << "input maze:" << endl;
    InputMaze(width, height);
    cout << "input maze start position:\t";
    cin >> startPosition.x >> startPosition.y;
    cout << "input maze end position:\t";
    std::cin >> endPosition.x >> endPosition.y;

    ExploreMaze(stack, startPosition, endPosition);

    Travel(stack);


    /*
     * 课件测试用例：

    15
    11
    1 0 1 1 1 0 0 1 1 1 0 0 0 0 0
    0 1 1 1 0 0 1 0 0 0 1 1 0 0 0
    1 0 0 1 1 1 1 0 0 0 0 1 1 0 0
    0 0 1 0 0 0 0 1 0 0 1 0 0 1 1
    0 0 1 0 1 1 0 1 0 0 0 0 0 0 0
    1 1 0 0 1 0 0 0 1 0 1 1 0 0 0
    1 0 0 0 0 1 1 0 0 0 0 0 0 0 0
    1 1 0 0 1 0 0 1 0 0 0 0 0 1 0
    0 0 1 1 1 0 0 1 0 0 1 1 1 1 1
    1 1 0 0 0 0 0 1 1 1 0 0 0 0 1
    1 0 1 1 0 0 0 0 0 1 0 0 0 0 1
    1 1
    15 11

    */
}
