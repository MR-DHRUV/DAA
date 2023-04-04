#include <bits/stdc++.h>
#include <fstream>
#define ll long long int

using namespace std;
using namespace std::chrono;

template <class T>
class SortAlgo
{
public:
    void writeOutput(T *arr, T n, std::ostream &out, std::string sort_algo)
    {
        std::string file_name = sort_algo + "_output.txt";

        ofstream file(file_name);

        for (T i = 0; i < n; i++)
        {
            file << arr[i] << endl;
        }
    }

    void bubbleSort(T *arr, T n)
    {
        for (T i = 0; i < n - 1; i++)
        {
            bool swapped = false;

            for (T j = 0; j < n - i - 1; j++)
            {

                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }

            if (!swapped)
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

class Plotter
{
    vector<int> sizes_;
    vector<double> bubble_time;
    vector<double> shell_time;
    vector<double> quick_time;
    vector<double> heap_time;

public:
    Plotter(const vector<int> &sizes, const vector<double> &shell_time, const vector<double> &bubble_time, const vector<double> &quick_time, const vector<double> &heap_time)
    {
        this->sizes_ = sizes;
        this->bubble_time = bubble_time;
        this->shell_time = shell_time;
        this->quick_time = quick_time;
        this->heap_time = heap_time;
    }
};
int main()
{
    // init
    int arr[] = {5, 10, 20, 100, 500, 1000, 2500, 10000, 25000, 50000, 75000, 100000};
    int n = sizeof(arr) / sizeof(arr[0]);

    // time vs n data
    vector<int> sizes;
    vector<double> bubble_time;
    vector<double> shell_time;
    vector<double> quick_time;
    vector<double> heap_time;

    // Generate files and measure time for each algorithm
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

        // Measure shell sort time
        auto start = high_resolution_clock::now();
        SortAlgo<ll> obj1;
        obj1.shellSort(arr, n);
        auto stop = high_resolution_clock::now();
        std::chrono::duration<double> comp_time1 = (stop - start);
        double shell_cpu_time = comp_time1.count();
        ofstream out1("sorted_" + to_string(arr[i]) + ".txt");
        obj1.writeOutput(arr, n, out1, "shell");
        out1.close();

        // Measure bubble sort time
        start = high_resolution_clock::now();
        SortAlgo<ll> obj2;
        obj2.bubbleSort(arr, n);
        stop = high_resolution_clock::now();
        std::chrono::duration<double> comp_time2 = (stop - start);
        double bubble_cpu_time = comp_time2.count();
        ofstream out2("sorted_" + to_string(arr[i]) + ".txt");
        obj2.writeOutput(arr, n, out2, "bubble");
        out2.close();

        // Measure quick sort time
        start = high_resolution_clock::now();
        SortAlgo<ll> obj4;
        obj4.quickSort(arr, 0, n - 1);
        stop = high_resolution_clock::now();
        std::chrono::duration<double> comp_time3 = (stop - start);
        double quick_cpu_time = comp_time3.count();
        ofstream out3("sorted_" + to_string(arr[i]) + ".txt");
        obj4.writeOutput(arr, n, out3, "quick");
        out3.close();

        // Measure heap sort time
        start = high_resolution_clock::now();
        SortAlgo<ll> obj5;
        obj5.heapSort(arr, n);
        stop = high_resolution_clock::now();
        std::chrono::duration<double> comp_time4 = (stop - start);
        double heap_cpu_time = comp_time4.count();

        // Store data in vectors
        sizes.push_back(n);
        bubble_time.push_back(bubble_cpu_time);
        shell_time.push_back(shell_cpu_time);
        quick_time.push_back(quick_cpu_time);
        heap_time.push_back(heap_cpu_time);

        // Write sorted data to output file
        ofstream out4("sorted_" + to_string(arr[i]) + ".txt");
        obj5.writeOutput(arr, n, out4, "heap");
        out4.close();

        // delete[] arr;
    }

    // Create plotter object with the time vs size data
    Plotter plotter(sizes, shell_time, bubble_time, quick_time, heap_time);

    return 0;
}