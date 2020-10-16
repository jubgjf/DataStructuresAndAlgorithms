#include "headers.h"

void TestExperiment1()
{
    cout << "===== Test for Experiment 1 =====" << endl;

    string testInputs[10] = {
        "1+1",
        "2*7-6",
        "23-8*9/3",
        "0/5-2*7+19",
        "45%5-9",
        "33-2*(-2.3+15.6*2)",
        "54*(7-3*2)",
        "3*(2*(3-8*2)-3)-12",
        "-8*2-(2%9)",
        "23.6%5*(21-2*1-34)"
    };

    for (int i = 0; i < 10; ++i)
    {
        cout << "test input:\t" << testInputs[i] << endl;
        string suffixStr = InfixToSuffix(testInputs[i]);
        cout << "suffix:\t" << suffixStr << endl;
        cout << "result:\t" << CalculateSuffix(suffixStr) << endl;
    }
}
