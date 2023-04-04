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

string to_format0(const string number, const int i)
{
    stringstream ss;
    ss << std::setw(i) << number;
    return ss.str();
}

string to_format1(long double time, const int i)
{
    stringstream ss;
    ss << std::setw(i) << time;
    return ss.str();
}

string getFileName(int j, int ele)
{
    string ans = "NUM-" + to_format(j + 1, 2) + "-" + to_format(ele, 6) + ".txt";
    return ans;
}

long long unsigned int insertionSort(ul arr[], int n)
{
    long long unsigned int count = 0;

    ul key;
    int i,j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;

            count++;
        }
        arr[j + 1] = key;
    }

    return count;
}

int main()
{
    // file sizes
    int arr[] = {5, 10, 20, 100, 500, 1000, 2500, 10000, 25000, 50000, 75000, 100000};
    int n = sizeof(arr) / sizeof(arr[0]);

    // time vs n data
    ofstream outp("insertionsort.txt");
    outp << to_format0("N", 6) << " " << to_format0("Average Time", 15) << " " << to_format0("Average Count", 15) << endl;

    // files
    for (int i = 0; i < n; i++)
    {
        // total time to sort m files of size n
        long double time = 0;
        long double totalCount = 0;

        for (int iter = 0; iter < 10; iter++)
        {
            // build file name
            string fileName = getFileName(iter, arr[i]);

            // read it
            ifstream inp(fileName);
            ul cnt;
            inp >> cnt;

            ul *data = new ul[arr[i]];

            ul k = 0;
            while (cnt--)
            {
                inp >> data[k++];
            }

            // init clock
            myTimer clk;

            // Start measuring CPU time
            clk.StartTimer();

            // call sort
            long long unsigned int count = insertionSort(data, arr[i]);

            // stop timer
            clk.EndTimer();

            // count
            if (totalCount == 0)
                totalCount = count;
            else
            {
                totalCount = (long double)(totalCount + (long double)count) / 2;
            }

            time += clk.GetInterval();
        }

        time /= arr[i];
        cout << "time : " << time << endl;
        outp << to_format1(arr[i], 6) << "    " << to_format1(time, 12) << "   " << to_format1(totalCount, 13) << endl;
    }

    return 0;
}