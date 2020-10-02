#include "headers.h"

string Trim(string str)
{
    while (true)
    {
        if (str[0] == ' ')
        {
            str.erase(0, 1);
        }
        else
        {
            break;
        }
    }

    return str;
}
