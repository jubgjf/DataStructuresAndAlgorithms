#pragma once


/* BasicOperations.cpp */

/// <summary>
/// 坐标
/// </summary>
struct Position
{
    int x;
    int y;
};

/// <summary>
/// 栈的节点
/// </summary>
struct node
{
    struct Position position;
    struct node* next;
};

/// <summary>
/// 生成空栈
/// </summary>
/// <returns>返回栈</returns>
node* InitStack();

/// <summary>
/// 将数据压栈
/// </summary>
/// <param name="stack">栈</param>
/// <param name="position">坐标</param>
void Push(node* stack, Position position);

/// <summary>
/// 弹栈
/// </summary>
/// <param name="stack">栈</param>
/// <returns>返回弹出的数据。若无数据，则返回-1</returns>
Position Pop(node* stack);

/// <summary>
/// 查询栈顶数据
/// </summary>
/// <param name="stack">栈</param>
/// <returns>返回栈顶数据。若无数据，则返回-1</returns>
Position Top(node* stack);

/// <summary>
/// 清空栈
/// </summary>
/// <param name="stack">栈</param>
void Clear(node* stack);

/// <summary>
/// 打印栈中所有数据
/// </summary>
/// <param name="stack">栈</param>
void Travel(node* stack);


/* Maze.cpp */

/**
 * \brief 迷宫最大宽度
 */
#define MAX_WIDTH 100

/**
 * \brief 迷宫最大高度
 */
#define MAX_HEIGHT 100

/// <summary>
/// 迷宫的一个单元格
/// </summary>
struct MazeGrid
{
    int passable;
    int hasPassed;
};

/// <summary>
/// 接受用户输入迷宫，0表示不能通过，1表示能通过
/// </summary>
/// <param name="width">迷宫宽度</param>
/// <param name="height">迷宫高度</param>
void InputMaze(int width, int height);

/// <summary>
/// 检索指定坐标周围的一个可走位置
/// </summary>
/// <param name="position">指定坐标</param>
/// <returns>返回指定坐标周围一圈的一个可走位置。若不存在可走位置，则返回{-1, -1}</returns>
Position GetAdjoin(Position position);

/// <summary>
/// 判断两个位置是否一致
/// </summary>
/// <param name="position1">位置1</param>
/// <param name="position2">位置2</param>
/// <returns>若位置一致则返回true，否则返回false</returns>
bool operator==(const Position& position1, const Position& position2);

/// <summary>
/// 判断两个位置是否不一致
/// </summary>
/// <param name="position1">位置1</param>
/// <param name="position2">位置2</param>
/// <returns>若位置不一致则返回true，否则返回false</returns>
bool operator!=(const Position& position1, const Position& position2);

/// <summary>
/// 走迷宫
/// </summary>
/// <param name="stack">栈</param>
/// <param name="startPosition">起始位置</param>
/// <param name="endPosition">结束位置</param>
void ExploreMaze(node* stack, Position startPosition, Position endPosition);


/* Homework3.cpp */

/// <summary>
/// 作业三的测试
/// </summary>
void TestHomework3();
