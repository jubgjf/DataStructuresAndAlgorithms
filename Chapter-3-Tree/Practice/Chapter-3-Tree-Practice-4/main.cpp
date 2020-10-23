#include"header.h"

int main()
{
    Pool* pool = init(0, 12);
    add(pool, 0, 4);
    add(pool, 1, 7);
    add(pool, 1, 9);
    add(pool, 0, 3);
    add(pool, 4, 5);
    add(pool, 3, 1);
    add(pool, -1, 89);
    add(pool, 7, 8);
    add(pool, -1, 9);
    add(pool, 2, 89);

    find_root(pool, 3);
    find_root(pool, 4);
    find_root(pool, 5);
    find_root(pool, 6);
    find_root(pool, 7);
    find_root(pool, 8);
    find_root(pool, 9);
    find_root(pool, 10);

    union_set(pool, 0, 7);

    find_root(pool, 3);
    find_root(pool, 4);
    find_root(pool, 5);
    find_root(pool, 6);
    find_root(pool, 7);
    find_root(pool, 8);
    find_root(pool, 9);
    find_root(pool, 10);

}
