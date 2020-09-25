//
// @brief: 栈练习
//

#include <cstdlib>

/// <summary>
/// 栈中数据类型
/// </summary>
typedef int elementType;

/// <summary>
/// 栈的节点
/// </summary>
struct node
{
    elementType data;
    struct node* next;
};

/// <summary>
/// 生成空栈
/// </summary>
/// <returns>返回栈</returns>
node* InitStack()
{
    node* top = (node*)malloc(sizeof(node));
    top->next = nullptr;

    return top;
}

/// <summary>
/// 将数据压栈
/// </summary>
/// <param name="stack">栈</param>
/// <param name="data">数据</param>
void Push(node* stack, elementType data)
{
    node* pushNode = (node*)malloc(sizeof(node));
    pushNode->data = data;
    pushNode->next = stack->next;
    stack->next = pushNode;
}

/// <summary>
/// 弹栈
/// </summary>
/// <param name="stack">栈</param>
/// <returns>弹出的数据。若无数据，则返回-1</returns>
elementType Pop(node* stack)
{
    node* popNode = stack->next;

    if (popNode == nullptr)
    {
        return -1;
    }

    stack->next = popNode->next;
    elementType popData = popNode->data;
    free(popNode);

    return popData;
}

/// <summary>
/// 查询栈顶数据
/// </summary>
/// <param name="stack">栈</param>
/// <returns>返回栈顶数据</returns>
elementType Top(node* stack)
{
    return stack->next->data;
}

/// <summary>
/// 清空栈
/// </summary>
/// <param name="stack">栈</param>
void Empty(node* stack)
{
    // TODO 节点未释放空间

    stack->next = nullptr;
}

int main()
{
    node* stack = InitStack();

    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);
    Push(stack, 4);

    Pop(stack);
    Pop(stack);

    Push(stack, 5);

    Pop(stack);

    Top(stack);

    Empty(stack);

    return 0;
}
