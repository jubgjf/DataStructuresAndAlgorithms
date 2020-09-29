#pragma once

#include <iostream>
#include "BasicOperations.h"
#include "Maze.h"

using namespace std;

/// <summary>
/// ���Թ�
/// </summary>
/// <param name="stack">ջ</param>
/// <param name="startPosition">��ʼλ��</param>
/// <param name="endPosition">����λ��</param>
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
/// ��ҵ���Ĳ���
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
     * �μ�����������

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
