#include "header.h"

int main()
{
    // char s[] = "asd";
    // char t[] = "111";

    string s = Init("abccaabcbacbca");
    string t = Init("bca");

    string r = Delete(s, t);
    return 0;
}
