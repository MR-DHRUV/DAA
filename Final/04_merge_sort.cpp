#include <iostream>
using namespace std;


void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}


// 1 array ko half me break krte jao jab tak har element alag alag na ho jaye
// then un parts ko sorted order me join krte jaoo

// faster than bubble , insertion and selection sort

// Approach I
// create new array of hal size and copy values

// Approach II
// use indexes , (calculate mid ...)

void merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    // length haii index nahi isiliye +1 hua
    int len1 = mid - start + 1;

    // end has already 1 added
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

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

void mergeSortI(int *arr, int start, int end)
{
    // base case

    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    // sorting left part;
    mergeSortI(arr, start, mid);

    // sorting right part;
    mergeSortI(arr, mid + 1, end);

    merge(arr, start, end);
}

int main()
{

    int arr[] = {6, 8, 3, 5, 9, 2, 1, 2, 4, 0};

    mergeSortI(arr,0 , 10);
    printArr(arr , 10);
    return 0;
}