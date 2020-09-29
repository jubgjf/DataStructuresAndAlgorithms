#pragma once

#include <iostream>
#include "BasicOperations.h"
#include "Maze.h"

using namespace std;

/// <summary>
/// 走迷宫
/// </summary>
/// <param name="stack">栈</param>
/// <param name="startPosition">起始位置</param>
/// <param name="endPosition">结束位置</param>
void ExploreMaze(node* stack, Position startPosition, Position endPosition)
{
    Position currentPosition = startPosition;
    maze[currentPosition.y][currentPosition.x].hasPassed = 1;

    while (currentPosition != endPosition)
    {
        Position possiblePosition = GetAdjoin(currentPosition);
        if (possiblePosition == Position{-1, -1})
        {
            Pop(stack);
            possiblePosition = Pop(stack);
        }
        currentPosition = possiblePosition;
        Push(stack, currentPosition);
        maze[currentPosition.y][currentPosition.x].hasPassed = 1;
    }
}

/// <summary>
/// 作业三的测试
/// </summary>
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
