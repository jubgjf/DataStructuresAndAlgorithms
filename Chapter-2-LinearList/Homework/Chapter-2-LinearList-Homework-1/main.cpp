#include "BasicOperations.h"
#include "Homework1_1.h"
#include "Homework1_2.h"

int main()
{
    std::cout << "===== Test for homework 1-1-1 =====" << std::endl;
    TestHomework1_1_1(6, 0, 1, 2, 3, 4, 5, 6);
    TestHomework1_1_1(0, 0);
    TestHomework1_1_1(0, 1, 1, 2);
    TestHomework1_1_1(5, 4, 1, 2, 3, 4, 5);
    TestHomework1_1_1(3, 7, 1, 2, 3);
    std::cout << std::endl;

    std::cout << "===== Test for homework 1-1-2 =====" << std::endl;
    TestHomework1_1_2(6, MIDDLE_FRONT, 1, 2, 3, 4, 5, 6);
    TestHomework1_1_2(6, MIDDLE_BACK, 1, 2, 3, 4, 5, 6);
    TestHomework1_1_2(5, MIDDLE_FRONT, 1, 2, 3, 4, 5);
    TestHomework1_1_2(5, MIDDLE_BACK, 1, 2, 3, 4, 5);
    TestHomework1_1_2(0, MIDDLE_BACK);
    std::cout << std::endl;

    std::cout << "===== Test for homework 1-2 =====" << std::endl;
    TestHomework1_2(5, 1, 2, 3, 4, 5);
    TestHomework1_2(0);
    TestHomework1_2(2, 1, 2);
    TestHomework1_2(4, 1, 2, 0, 9);

    system("pause");

    return 0;
}
