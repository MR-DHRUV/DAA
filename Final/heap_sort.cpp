#include <bits/stdc++.h>
#define ul unsigned long
using namespace std;

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

    return 0;
}