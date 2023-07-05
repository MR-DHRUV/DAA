#include<bits/stdc++.h>
using namespace std;


unsigned long* CountingSort(unsigned long data[], long Size)
{
    unsigned long maxEle = 0;
    
    for (long i = 0; i < Size; i++)
    {
        maxEle = max(maxEle,data[i]);
    }

    // count of occurances of each element
    unsigned long* count = new unsigned long[maxEle+1];

    for (int i = 0; i <= maxEle; i++)
    {
        count[i] = 0;
    }
    
    for (long i = 0; i < Size; i++)
    {
        count[data[i]]++;
    }

    // modifying original array to store data 
    long j = 0;

    for (long i = 0; i <= maxEle; i++)
    {
        while (count[i]--)
        {
            data[j++] = i;
        }
    }
    
    return data;
}

int main()
{
    // ginti krko konsa kitni baar haii 
    // O(max element) time but space = O(max element)

    // if array is like 1 2 1000000
    // space used will be 1000000

    unsigned long data[] = {1, 4, 1, 2, 7, 5, 2};
    long Size = sizeof(data) / sizeof(data[0]);

    unsigned long* sortedData = CountingSort(data, Size);

    // print data
    for (int i = 0; i < Size; i++)
    {
        cout<<sortedData[i]<<" ";
    }
    
    return 0;
}