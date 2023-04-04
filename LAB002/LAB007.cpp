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

// heap sort
void heapify(ul arr[], int n, int i, long long unsigned int &count)
{
    ul left = (2 * i) + 1;

    while (left < n)
    {
        ul right = left + 1;

        // checking for right
        if (right < n && arr[right] > arr[left])
        {
            if (arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
                left = (2 * i) + 1;
                count++;
            }
            else
            {
                break;
            }
        }
        else if (arr[i] < arr[left])
        {
            swap(arr[i], arr[left]);
            i = left;
            left = (2 * i) + 1;
            count++;
        }
        else
        {
            break;
        }
    }
}

void buildHeap(ul arr[], int n, long long unsigned int &count)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i, count);
    }
}

void del(ul arr[], int n, long long unsigned int &count)
{
    if (n < 1)
    {
        return;
    }

    swap(arr[0], arr[n]);
    heapify(arr, n, 0, count);
}

long long unsigned int heapSort(ul arr[], int n)
{
    long long unsigned int count = 0;

    buildHeap(arr, n, count);

    for (int i = n - 1; i >= 0; i--)
    {
        del(arr, i, count);
    }

    return count;
}

int main()
{
    // file sizes
    int arr[] = {5, 10, 20, 100, 500, 1000, 2500, 10000, 25000, 50000, 75000, 100000};
    int n = sizeof(arr) / sizeof(arr[0]);

    // time vs n data
    ofstream outp("heapsort.txt");
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
            long long unsigned int count = heapSort(data, arr[i]);

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