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

void merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    int len1 = mid - start + 1;

    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

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

    int index1 = 0;
    int index2 = 0;

    k = start;

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

    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSortI(arr, start, mid);
    mergeSortI(arr, mid + 1, end);
    merge(arr, start, end);
}

int main()
{
    int arr[] = {6, 8, 3, 5, 9, 2, 1, 2, 4, 0};
    mergeSortI(arr, 0, 10);
    printArr(arr, 10);
    return 0;
}