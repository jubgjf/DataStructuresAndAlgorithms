#include "headers.h"

int main()
{
    TestExperiment1();

    cout << "=== you can input your test now === " << endl;

    string inputStr;
    cin >> inputStr;

    try
    {
        string suffixStr = InfixToSuffix(inputStr);
        cout << "suffix:\t" << suffixStr << endl;
        cout << "result:\t" << CalculateSuffix(suffixStr) << endl;
    }
    catch (exception e)
    {
        cout << "Error";
    }

    return 0;
}
