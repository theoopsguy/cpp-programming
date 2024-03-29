#include <iostream>
using namespace std;

//assuming array is sorted
/*
if elements are from 1, another approach can be to find sum of n natural nos. and the diff of this sum with
the sum of all elements of the array is the missing element.
*/

int minEle(int arr[], int size)
{
    int m = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < m)
            m = arr[i];
    }

    return m;
}

int main()
{
    int arr[10] = {6, 7, 9, 10, 11, 12, 13, 15, 16, 18};
    int minimum = minEle (arr, 10);
    int diff = minimum - 0;
    for (int idx = 0; idx < 10; idx++)
    {
        if (arr[idx] - idx != diff)
        {
            cout<<idx + diff<<endl;
            diff = arr[idx] - idx;
        }
         
    }

    return 0;
}