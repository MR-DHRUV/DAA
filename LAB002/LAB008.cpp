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

void merge(ul *arr, int start, int end, long long unsigned int &count)
{
    int mid = start + (end - start) / 2;

    // length haii index nahi isiliye +1 hua
    int len1 = mid - start + 1;

    // end has already 1 added
    int len2 = end - mid;

    ul *first = new ul[len1];
    ul *second = new ul[len2];

    // copying half arrays (total complexity : O(N) )
    int k = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k];
        k++;
    }

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k];
        k++;
    }

    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;

    // index of main array
    k = start;

    // Total complexity : O(N)
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[k++] = first[index1++];
        }
        else
        {
            arr[k++] = second[index2++];
        }

        count++;
    }

    // agar koi part lamba hua
    while (index1 < len1)
    {
        arr[k++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[k++] = second[index2++];
    }
}

void mergeSortI(ul *arr, int start, int end, long long unsigned int &count)
{
    // base case

    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    // sorting left part;
    mergeSortI(arr, start, mid,count);

    // sorting right part;
    mergeSortI(arr, mid + 1, end, count);

    merge(arr, start, end, count);
}


int main()
{
    // file sizes
    int arr[] = {5, 10, 20, 100, 500, 1000, 2500, 10000, 25000, 50000, 75000, 100000};
    int n = sizeof(arr) / sizeof(arr[0]);

    // time vs n data
    ofstream outp("mergesort.txt");
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
            long long unsigned int count = 0;
            mergeSortI(data,0, arr[i]-1,count);

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