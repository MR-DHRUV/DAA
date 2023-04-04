#include <bits/stdc++.h>
#include <fstream>
#include <iomanip>
#include "myAuxFunctions.h"
#include "myRandom.h"
#include "myTimer.h"

#define ul unsigned long
using namespace std;

// formatter to convert int to number fixed to i places
string to_format(const int number, const int i)
{
    stringstream ss;
    ss << std::setw(i) << std::setfill('0') << number;
    return ss.str();
}

int main(int argc, char const *argv[])
{
    vector<ul> inputs(argc + 1);
    // n m s

    // fetching arg
    for (int i = 0; i < argc; i++)
    {
        inputs[i] = StrToULong(argv[i]);
    }

    inputs.erase(inputs.begin());

    // init a LCG generator
    myRandom generator(1L, 1e9, 1664525L, 1664525L, 75957137);

    // set seed if provided
    if (argc >= 4)
        generator.setSeed(inputs[2]);

    long double time = 0;

    // generating m times nrandom numbers
    for (int i = 0; i < inputs[1]; i++)
    {
        // init clock
        myTimer clk;

        // init file
        string fileName = "NUM-" + to_format(i + 1, 2) + "-" + to_format(inputs[0], 6) + ".txt";
        cout << fileName << endl;

        ofstream file(fileName);
        file << inputs[0] << endl;

        // start clock
        clk.StartTimer();

        for (int j = 0; j < inputs[0]; j++)
        {
            file << generator() << endl;
        }

        // end clock
        clk.EndTimer();

        time += clk.GetInterval();
    }

    cout << "Average Time Taken: " << (time / (long double)inputs[1]) << " seconds" << endl;

    return 0;
}