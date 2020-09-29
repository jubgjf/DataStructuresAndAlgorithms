#pragma once

/**
 * \brief 迷宫最大宽度
 */
#define MAX_WIDTH 100

/**
 * \brief 迷宫最大高度
 */
#define MAX_HEIGHT 100

/// <summary>
/// 坐标
/// </summary>
struct Position
{
    int x;
    int y;
};

/// <summary>
/// 迷宫的一个单元格
/// </summary>
struct MazeGrid
{
    int passable;
    int hasPassed;
};

/// <summary>
/// 迷宫
/// </summary>
MazeGrid maze[MAX_HEIGHT][MAX_WIDTH];

/// <summary>
/// 接受用户输入迷宫，0表示不能通过，1表示能通过
/// </summary>
/// <param name="width">迷宫宽度</param>
/// <param name="height">迷宫高度</param>
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

/// <summary>
/// 检索指定坐标周围的一个可走位置
/// </summary>
/// <param name="position">指定坐标</param>
/// <returns>返回指定坐标周围一圈的一个可走位置。若不存在可走位置，则返回{-1, -1}</returns>
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

/// <summary>
/// 判断两个位置是否一致
/// </summary>
/// <param name="position1">位置1</param>
/// <param name="position2">位置2</param>
/// <returns>若位置一致则返回true，否则返回false</returns>
bool operator==(const Position& position1, const Position& position2)
{
    return position1.x == position2.x && position1.y == position2.y;
}

/// <summary>
/// 判断两个位置是否不一致
/// </summary>
/// <param name="position1">位置1</param>
/// <param name="position2">位置2</param>
/// <returns>若位置不一致则返回true，否则返回false</returns>
bool operator!=(const Position& position1, const Position& position2)
{
    return !(position1.x == position2.x && position1.y == position2.y);
}
