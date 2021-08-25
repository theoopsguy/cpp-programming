#include <iostream>
using namespace std;

//assuming array is sorted
/*
can also use a seive like approach like marking all the indices of a second array (of size-the maximum 
element in primary array) corresponding to the elements present in the primary array and then the unmarked 
elements of the secondary array will be the ones missing.
This approach is a rudimentary form of hashing/bitset.
for this array need not be sorted
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
    int arr[10] = {5, 6, 7, 10, 11, 13, 14, 15, 16, 19};
    int minimum = minEle (arr, 10);
    int diff = minimum - 0;
    for (int idx = 0; idx < 10; idx++)
    {
        if (arr[idx] - idx != diff)
        {
            while (diff < arr[idx] - idx)
            {
                cout<<idx + diff<<endl;
                diff++;
            }
        }
         
    }

    return 0;
}