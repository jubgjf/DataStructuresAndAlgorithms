#include <iostream>
#include "header.h"

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
            std::cin >> maze[i][j].passable;
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
