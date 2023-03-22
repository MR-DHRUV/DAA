#include <bits/stdc++.h>
#include <fstream>
#define ll long long int

using namespace std;
using namespace std::chrono;

template <class T>
class SortAlgo
{
public:
    void writeOutput(T *arr, T n)
    {
        ofstream file("sort_output.txt");

        for (T i = 0; i < n; i++)
        {
            file << arr[i] << endl;
        }
    }

    void bubbleSort(T *arr, T n)
    {
        for (T i = 0; i < n - 1; i++)
        {
            bool isSwaped = false;

            for (T j = 0; j < n - i - 1; j++)
            {

                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    isSwaped = true;
                }
            }

            if (!isSwaped)
            {
                break;
            }
        }
    }

    // shell sort
    void shellSort(T arr[], T n)
    {
        for (T gap = n / 2; gap > 0; gap /= 2)
        {
            for (T i = gap; i < n; i += 1)
            {
                T temp = arr[i];

                T j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];

                arr[j] = temp;
            }
        }
    }

    // quick sort
    T partition(T arr[], T start, T end)
    {
        T pivot = arr[start];

        T cnt = 0;
        for (T i = start + 1; i <= end; i++)
        {
            if (arr[i] <= pivot)
            {
                cnt++;
            }
        }

        // now we have no of elements less than or equal to pivot

        // placing pivot at its right position
        T pivotIndex = start + cnt;
        swap(arr[pivotIndex], arr[start]);

        // left and right wala paart sahi krna haii taaki usne greater aur lesser elements ho

        T i = start;
        T j = end;

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

    void quickSortRec(T arr[], T start, T end)
    {
        // if equal then arr of size 1 and when start > end then size 0 , already sorted case
        if (start >= end)
        {
            return;
        }

        // partition krenge aur 1st element ko uski sahi jagah par lagayenge
        T p = partition(arr, start, end);

        // sorting left part
        quickSortRec(arr, start, p - 1);

        // sorting right part
        quickSortRec(arr, p + 1, end);
        return;
    }

    void quickSort(T arr[], T start, T end)
    {
        bool sorted = true;

        // optimization to (NlogN)
        for (int i = start; i < end - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                sorted = false;
            }
        }

        if (sorted)
            return;

        quickSortRec(arr, start, end);
    }

    // heap sort
    void heapify(T arr[], T n, T i)
    {
        T left = (2 * i) + 1;

        while (left < n)
        {
            T right = left + 1;

            // checking for right
            if (right < n && arr[right] > arr[left])
            {
                if (arr[i] < arr[right])
                {
                    swap(arr[i], arr[right]);
                    i = right;
                    left = (2 * i) + 1;
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
            }
            else
            {
                break;
            }
        }
    }

    void buildHeap(T arr[], T n)
    {
        for (T i = (n / 2) - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

    void del(T arr[], T n)
    {
        if (n < 1)
        {
            return;
        }

        swap(arr[0], arr[n]);
        heapify(arr, n, 0);
    }

    void heapSort(T arr[], T n)
    {
        buildHeap(arr, n);

        for (T i = n - 1; i >= 0; i--)
        {
            del(arr, i);
        }
    }
};

int main()
{
    // init
    int arr[] = {5, 10, 20, 100, 500, 1000, 2500, 10000, 25000, 50000, 75000, 100000};
    int n = sizeof(arr) / sizeof(arr[0]);

    // time vs n data
    ofstream outp("output.txt");

    // Generate files
    for (int i = 0; i < n; i++)
    {
        ifstream inp("random_" + to_string(arr[i]) + ".txt");

        ll n;
        inp >> n;

        ll *arr = new ll[n];

        ll j = n;
        ll k = 0;

        while (j--)
        {
            inp >> arr[k++];
        }

        // Start measuring CPU time
        auto start = high_resolution_clock::now();

        // call sort
        SortAlgo<ll> obj;
        obj.bubbleSort(arr, n);

        // Stop measuring CPU time
        auto stop = high_resolution_clock::now();

        // Calculate the CPU time
        auto duration = duration_cast<microseconds>(stop - start);
        double cpu_time = duration.count() / 1000000.0;

        outp << n << " " << cpu_time << endl;

        // write sorted data
        obj.writeOutput(arr, n);
    }

    return 0;
}
