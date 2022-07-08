#include <iostream>
using namespace std;

/*
Test case: 
size = 10
elements: 3, 5, 5, 7, 9, 10, 10, 10, 11, 13
*/

int main()
{
    int size;
    cin>>size;
    int *arr = new int[size];

    for (int iidx = 0; iidx < size; iidx++)
    {
        cin>>arr[iidx];
    }

    for (int ptr1 = 0; ptr1 < size-1; )
    {
        if (arr[ptr1] == arr[ptr1 + 1])
        {
            int ptr2 = ptr1 + 2;
            while(arr[ptr2] == arr[ptr1])
            {
                ptr2++;
            }
            cout<<arr[ptr1]<<" appears "<<ptr2-ptr1<<" times.\n";
            ptr1 = ptr2;
        }
        else
        {
            ptr1++;
        }
    }
    return 0;
}