#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    int cnt = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // now we have no of elements less than or equal to pivot

    // placing pivot at its right position
    int pivotIndex = start + cnt;
    swap(arr[pivotIndex], arr[start]);

    // left and right wala paart sahi krna haii taaki usne greater aur lesser elements ho

    int i = start;
    int j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    // if equal then arr of size 1 and when start > end then size 0 , already sorted case
    if (start >= end)
    {
        return;
    }

    // partition krenge aur 1st element ko uski sahi jagah par lagayenge
    int p = partition(arr, start, end);

    // sorting left part
    quickSort(arr, start, p - 1);
    printArr(arr,4);

    // sorting right part
    quickSort(arr, p + 1, end);
    printArr(arr,4);


    return;
}

int main()
{
    // it works on a principle that an element is said to be at a sorted position when all the elements after it are larger than it and all the elements before it are smaller than it irrespective of their order;
    // element will try to find their own place.

    // 50 70 60 90 40 80 10 20 30
    // take 1st element as pivot i.e 50
    // i = 50 , j = 30 (last element);

    // i will be looking for element greater than pivot
    // j will be looking for element smaller than or equal to pivot

    // 50 apni jagah dhund raha haii sunch that usse aage sab small ho aur usse peeche sab large irrespective of their order

    // 50 70 60 90 40 80 10 20 30
    // 50 30 60 90 40 80 10 20 70
    // 50 30 20 90 40 80 10 60 70
    // 50 30 20 10 40 80 90 60 70

    // iteration 1 complete, 50 took its right place
    // 30 20 10 40 50 80 90 60 70
    // at this time j will be at index of 50

    // ab 2 half lists sort krni hain
    // ab inpr quick sort lagao

    // 30 20 10 40 50 80 90 60 70
    // 30 10 20 40 50 80 90 60 70
    // 10 20 30 40 50 80 90 60 70
    //.....

    // worst case ; when the list is already sorted in any order : O(N^2);
    // best case ; when the first element sets at middle : O(NlogN);
    // avrage case : O(NlogN);

    // this is not the fastest sort

    // ALSO CALLED selection exchange sort , partion exchange sort

    int arr[] = {2,8,5,4};
    int n = 4;
    // int arr[] = {6, 8, 3, 5, 9, 2, 1, 2, 4, 0};
    // int n = 10;

    quickSort(arr, 0, n-1);
    printArr(arr,4);

    return 0;
}

// not adaptive
// not stable