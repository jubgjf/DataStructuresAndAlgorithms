#include "UnionSet.h"

Pool* InitUnionSetPool(int rootIndex, int rootData)
{
    Pool* pool = new Pool;
    pool->lastIndex = 0;
    pool->element[rootIndex] = Element{ rootData,-1 };

    return pool;
}

void UnionSets(Pool* pool, int root1Index, int root2Index)
{
    pool->element[root1Index].parent = root2Index;
}

int FindRoot(Pool* pool, int index)
{
    int tmp_root = index;
    while (pool->element[tmp_root].parent != -1)
    {
        tmp_root = pool->element[tmp_root].parent;
    }

    // 查询后合并
    if (tmp_root != index)
    {
        pool->element[index].parent = tmp_root;
    }

    return tmp_root;
}

void AddElement(Pool* pool, int parent, int data)
{
    pool->element[pool->lastIndex + 1] = Element{ data,parent };
    pool->lastIndex++;
}
