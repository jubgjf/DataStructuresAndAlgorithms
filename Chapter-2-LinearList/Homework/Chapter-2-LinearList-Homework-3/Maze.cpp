#include <cmath>
#include <cstdlib>
#include <iostream>
#include "header.h"

using namespace std;

/// <summary>
/// 迷宫
/// </summary>
MazeGrid maze[MAX_HEIGHT][MAX_WIDTH];

void InputMaze(int width, int height)
{
    for (int i = 1; i < height + 1; ++i) // 迷宫周围留出一圈"0"
    {
        for (int j = 1; j < width + 1; ++j)
        {
            cin >> maze[i][j].passable;
        }
    }
}

Position GetAdjoin(Position position)
{
    for (int i = position.y - 1; i <= position.y + 1; ++i)
    {
        for (int j = position.x - 1; j <= position.x + 1; ++j)
        {
            if (i == position.y && j == position.x) { continue; }

            if (maze[i][j].passable == 1 && maze[i][j].hasPassed == 0)
            {
                return Position{j, i};
            }
        }
    }

    return Position{-1, -1};
}

bool operator==(const Position& position1, const Position& position2)
{
    return position1.x == position2.x && position1.y == position2.y;
}

bool operator!=(const Position& position1, const Position& position2)
{
    return !(position1.x == position2.x && position1.y == position2.y);
}

void ExploreMaze(node* stack, Position startPosition, Position endPosition)
{
    Position currentPosition = startPosition;
    maze[currentPosition.y][currentPosition.x].hasPassed = 1;
    Push(stack, startPosition);

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

bool IsAdjoin(Position position1, Position position2)
{
    return abs(position1.x - position2.x) <= 1 && abs(position1.y - position2.y) <= 1;
}

void ImprovePath(node* stack, Position startPosition, Position endPosition)
{
    int stackSize = GetSize(stack);
    Position* path = (Position*)malloc(sizeof(Position) * stackSize);

    for (int i = 0; i < stackSize; ++i)
    {
        path[i] = Pop(stack);
    }

    for (int i = stackSize - 1; i >= 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (path[j] == Position{-1, -1}) { continue; }

            if (IsAdjoin(path[i], path[j]))
            {
                for (int k = j + 1; k < i; k++)
                {
                    path[k] = Position{-1, -1};
                }
            }
        }
    }

    Clear(stack);

    for (int i = 0; i < stackSize; ++i)
    {
        if (path[i] == Position{-1, -1}) { continue; }
        Push(stack, path[i]);
    }
}
