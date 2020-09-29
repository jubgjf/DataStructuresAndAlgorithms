#pragma once

/**
 * \brief �Թ������
 */
#define MAX_WIDTH 100

/**
 * \brief �Թ����߶�
 */
#define MAX_HEIGHT 100

/// <summary>
/// ����
/// </summary>
struct Position
{
    int x;
    int y;
};

/// <summary>
/// �Թ���һ����Ԫ��
/// </summary>
struct MazeGrid
{
    int passable;
    int hasPassed;
};

/// <summary>
/// �Թ�
/// </summary>
MazeGrid maze[MAX_HEIGHT][MAX_WIDTH];

/// <summary>
/// �����û������Թ���0��ʾ����ͨ����1��ʾ��ͨ��
/// </summary>
/// <param name="width">�Թ����</param>
/// <param name="height">�Թ��߶�</param>
void InputMaze(int width, int height)
{
    for (int i = 1; i < height + 1; ++i) // �Թ���Χ����һȦ"0"
    {
        for (int j = 1; j < width + 1; ++j)
        {
            std::cin >> maze[i][j].passable;
        }
    }
}

/// <summary>
/// ����ָ��������Χ��һ������λ��
/// </summary>
/// <param name="position">ָ������</param>
/// <returns>����ָ��������ΧһȦ��һ������λ�á��������ڿ���λ�ã��򷵻�{-1, -1}</returns>
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
/// �ж�����λ���Ƿ�һ��
/// </summary>
/// <param name="position1">λ��1</param>
/// <param name="position2">λ��2</param>
/// <returns>��λ��һ���򷵻�true�����򷵻�false</returns>
bool operator==(const Position& position1, const Position& position2)
{
    return position1.x == position2.x && position1.y == position2.y;
}

/// <summary>
/// �ж�����λ���Ƿ�һ��
/// </summary>
/// <param name="position1">λ��1</param>
/// <param name="position2">λ��2</param>
/// <returns>��λ�ò�һ���򷵻�true�����򷵻�false</returns>
bool operator!=(const Position& position1, const Position& position2)
{
    return !(position1.x == position2.x && position1.y == position2.y);
}
