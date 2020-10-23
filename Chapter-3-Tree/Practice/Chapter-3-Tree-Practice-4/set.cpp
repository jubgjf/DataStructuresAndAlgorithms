#include "header.h"

Pool* init(int root_index, int root_data)
{
    Pool* pool = new Pool;
    pool->last_index = 0;
    pool->element[root_index] = Element{ root_data,-1 };

    return pool;
}

void union_set(Pool* pool, int root1, int root2)
{
    pool->element[root1].parent = root2;
}

int find_root(Pool* pool, int index)
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

void add(Pool* pool, int parent, int data)
{
    pool->element[pool->last_index + 1] = Element{ data,parent };
    pool->last_index++;
}
