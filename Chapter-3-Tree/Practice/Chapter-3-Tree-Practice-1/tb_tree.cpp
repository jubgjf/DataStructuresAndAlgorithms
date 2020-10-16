#include "header.h"

int size(tree b_tree)
{
    // TODO 测试
    if (b_tree == nullptr) { return 0; }
    return size(b_tree->l_child) + size(b_tree->l_child) + 1;
}

int height(tree b_tree)
{
    // TODO 测试
    if (b_tree->l_child == nullptr && b_tree->r_child == nullptr) { return 1; }
    return MAX(height(b_tree->l_child), height(b_tree->r_child)) + 1;
}

void destroy(tree b_tree)
{
    // TODO 测试
    destroy(b_tree->l_child);
    destroy(b_tree->r_child);
    delete b_tree;
}

void mirror(tree b_tree)
{
}

void mirror_r(tree b_tree)
{
}

tree input()
{
    return nullptr;
}

tree input_r()
{
    return nullptr;
}

node* tb_next(tree tb_tree, node* node)
{
    return nullptr;
}

void init()
{
}

void pre_order(tree tb_tree)
{
}

void in_order(tree tb_tree)
{
}

void layer(tree b_tree, node** list, int& index)
{
}

void insert(tree tb_tree, node* position, node* node)
{
}

tree list_to_tree(node** list, int len)
{
    return nullptr;
}

tree copy(tree source)
{
    return nullptr;
}

tree copy_r(tree source)
{
    return nullptr;
}

bool equal(tree b_tree_1, tree b_tree_2)
{
    return false;
}
