#include <cstdlib>

/// <summary>
/// ջ����������
/// </summary>
typedef int elementType;

/// <summary>
/// ջ�Ľڵ�
/// </summary>
struct node
{
    elementType data;
    struct node* next;
};

/// <summary>
/// ���ɿ�ջ
/// </summary>
/// <returns>����ջ</returns>
node* InitStack()
{
    node* top = (node*)malloc(sizeof(node));
    top->next = nullptr;

    return top;
}

/// <summary>
/// ������ѹջ
/// </summary>
/// <param name="stack">ջ</param>
/// <param name="data">����</param>
void Push(node* stack, elementType data)
{
    node* pushNode = (node*)malloc(sizeof(node));
    pushNode->data = data;
    pushNode->next = stack->next;
    stack->next = pushNode;
}

/// <summary>
/// ��ջ
/// </summary>
/// <param name="stack">ջ</param>
/// <returns>���������ݡ��������ݣ��򷵻�-1</returns>
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
/// ��ѯջ������
/// </summary>
/// <param name="stack">ջ</param>
/// <returns>����ջ�����ݡ��������ݣ��򷵻�-1</returns>
elementType Top(node* stack)
{
    if (stack->next == nullptr)
    {
        return -1;
    }
    return stack->next->data;
}

/// <summary>
/// ���ջ
/// </summary>
/// <param name="stack">ջ</param>
void Empty(node* stack)
{
    // TODO �ڵ�δ�ͷſռ�

    stack->next = nullptr;
}