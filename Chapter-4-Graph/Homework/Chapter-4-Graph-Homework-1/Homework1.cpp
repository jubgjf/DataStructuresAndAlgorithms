#include "header.h"

int ManStatus(int statusNum)
{
    return statusNum >> 3 & 1;
}

int WolfStatus(int statusNum)
{
    return statusNum >> 2 & 1;
}

int SheepStatus(int statusNum)
{
    return statusNum >> 1 & 1;
}

int CabbageStatus(int statusNum)
{
    return statusNum & 1;
}

bool IsLegal(int status1Num, int status2Num)
{
    // �˱���ı�λ��
    if (ManStatus(status1Num) == ManStatus(status2Num))
    {
        return false;
    }

    // �Ǻ��򹲴�ʱ���˱����ڳ�
    if (WolfStatus(status1Num) == SheepStatus(status1Num))
    {
        if (WolfStatus(status1Num) != ManStatus(status1Num))
        {
            return false;
        }
    }
    if (WolfStatus(status2Num) == SheepStatus(status2Num))
    {
        if (WolfStatus(status2Num) != ManStatus(status2Num))
        {
            return false;
        }
    }

    // �˺��򹲴�ʱ���˱����ڳ�
    if (CabbageStatus(status1Num) == SheepStatus(status1Num))
    {
        if (CabbageStatus(status1Num) != ManStatus(status1Num))
        {
            return false;
        }
    }
    if (CabbageStatus(status2Num) == SheepStatus(status2Num))
    {
        if (CabbageStatus(status2Num) != ManStatus(status2Num))
        {
            return false;
        }
    }

    // һ�����ı�����λ��
    if (WolfStatus(status1Num) != WolfStatus(status2Num) &&
        SheepStatus(status1Num) != SheepStatus(status2Num) &&
        CabbageStatus(status1Num) == CabbageStatus(status2Num))
    {
        return false;
    }
    else if (WolfStatus(status1Num) != WolfStatus(status2Num) &&
        SheepStatus(status1Num) == SheepStatus(status2Num) &&
        CabbageStatus(status1Num) != CabbageStatus(status2Num))
    {
        return false;
    }
    else if (WolfStatus(status1Num) == WolfStatus(status2Num) &&
        SheepStatus(status1Num) != SheepStatus(status2Num) &&
        CabbageStatus(status1Num) != CabbageStatus(status2Num))
    {
        return false;
    }
    else if (WolfStatus(status1Num) != WolfStatus(status2Num) &&
        SheepStatus(status1Num) != SheepStatus(status2Num) &&
        CabbageStatus(status1Num) != CabbageStatus(status2Num))
    {
        return false;
    }

    return true;
}

void TestHomework1()
{
    int matrix[16][16] = {0};

    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 16; ++j)
        {
            if (IsLegal(i, j))
            {
                matrix[i][j] = 1;
            }
        }
    }

    Graph* graph = InitGraph(matrix, 16);
    Dijkstra(graph, 0, 15);
}
