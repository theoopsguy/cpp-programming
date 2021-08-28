#include <iostream>
using namespace std;

/*
Test case: 
size = 10
elements: 8, 5, 11, 7, 9, 10, 5, 10, 11, 10
*/

int maximum (int *arr, int size)
{
    int max = arr[0];
    for (int idx = 0; idx < size; idx++)
    {
        if (arr[idx] > max)
            max = arr[idx];
    }
    return max;
}

int main()
{
    int size;
    cin>>size;
    int *arr = new int[size];

    for (int iidx = 0; iidx < size; iidx++)
    {
        cin>>arr[iidx];
    }

    int m = maximum(arr, size);

    int *map = new int[m+1];

    for (int sidx = 0; sidx < size; sidx++)
    {
        map[arr[sidx]]++;
    }
    
    for (int dup = 0; dup < m+1; dup++)
    {
        if (map[dup] > 1)
            cout<<dup<<" appears "<<map[dup]<<" times.\n";
    }
    
    return 0;
}