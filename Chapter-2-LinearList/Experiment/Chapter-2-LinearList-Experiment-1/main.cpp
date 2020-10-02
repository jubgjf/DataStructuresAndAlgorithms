#include "headers.h"

int main()
{
    TestExperiment1();

    cout << "=== you can input your test now === " << endl;

    string inputStr;
    cin >> inputStr;

    string suffixStr = InfixToSuffix(inputStr);
    cout << "suffix:\t" << suffixStr << endl;

    cout << "result:\t" << CalculateSuffix(suffixStr) << endl;

    return 0;
}
