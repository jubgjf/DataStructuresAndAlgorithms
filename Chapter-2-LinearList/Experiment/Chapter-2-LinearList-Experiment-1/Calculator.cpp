#include "headers.h"

bool IsOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int GetPriority(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 0;
    case '*':
    case '/':
    case '%':
        return 1;
    default:
        return -1;
    }
}

string InfixToSuffix(string infixStr)
{
    node* operatorStack = InitStack();
    string suffixStr;

    if (infixStr[0] == '-') // 表达式开头就是负数
    {
        infixStr = "0" + infixStr;
    }

    for (int i = 0; ; ++i)
    {
        if (infixStr[i] == '\0') { break; }

        if (isdigit(infixStr[i]) || infixStr[i] == '.')
        {
            suffixStr += infixStr[i];
        }
        else
        {
            suffixStr += " ";

            if (infixStr[i] == ')')
            {
                while (Top(operatorStack)->data.op != '(')
                {
                    suffixStr += Pop(operatorStack)->data.op;
                }
                Pop(operatorStack);
            }
            else if (infixStr[i] == '(')
            {
                Push(operatorStack, infixStr[i]);

                if (infixStr[i + 1] == '-') // 括号内开头就是负数
                {
                    infixStr.insert(i + 1, 1, '0');
                }
            }
            else
            {
                while (true)
                {
                    if (IsEmpty(operatorStack) || Top(operatorStack)->data.op == '(' ||
                        GetPriority(infixStr[i]) > GetPriority(Top(operatorStack)->data.op))
                    {
                        break;
                    }
                    suffixStr += Pop(operatorStack)->data.op;
                }
                Push(operatorStack, infixStr[i]);
            }
        }
    }

    suffixStr += Travel(operatorStack);

    return suffixStr;
}

double CalculateSuffix(string suffixStr)
{
    node* numStack = InitStack();

    for (int i = 0; suffixStr.length() > 0; ++i)
    {
        if (!(isdigit(suffixStr[i]) || suffixStr[i] == '.'))
        {
            if (IsOperator(suffixStr[0]))
            {
                double num1 = Pop(numStack)->data.num;
                double num2 = Pop(numStack)->data.num;
                double result = ExecCalculate(num2, num1, suffixStr[0]);
                Push(numStack, result);
                suffixStr.erase(0, 1);
                suffixStr = Trim(suffixStr);
                i -= 1;
            }
            else
            {
                Push(numStack, stod(suffixStr));
                suffixStr.erase(0, i);
                suffixStr = Trim(suffixStr);
                i = -1;
            }
        }
    }

    return Top(numStack)->data.num;
}

double ExecCalculate(double num1, double num2, char op)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    case '%':
        return (int)num1 % (int)num2;
    default:
        return 0;
    }
}
