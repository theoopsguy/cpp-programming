#include <iostream>
using namespace std;
//input will be 2 sorted arrays and output will be an array which is a sorted union of both arrays.
int main()
{
    int *arr1 = new int [10];
    int *arr2 = new int [10];
    int *farr = new int [20];

    int n1, n2;
    cin>>n1>>n2;

    for (int i = 0; i < n1; i++)
    {
        cin>>arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin>>arr2[i];
    }
    
    int idx1 = 0, idx2 = 0, fidx = 0;

    while (idx1 < n1 || idx2 < n2)
    {
        if (idx1 == n1)
        {
            farr[fidx] = arr2[idx2];
            idx2++;
            fidx++;
        }
        else if (idx2 == n2)
        {
            farr[fidx] = arr1[idx1];
            idx1++;
            fidx++;
        }
        else if (arr1[idx1] < arr2[idx2])
        {
            farr[fidx] = arr1[idx1];
            idx1++;
            fidx++;
        }
        else if (arr1[idx1] > arr2[idx2])
        {
            farr[fidx] = arr2[idx2];
            idx2++;
            fidx++;
        }
        else if (arr1[idx1] == arr2[idx2])
        {
            farr[fidx] = arr2[idx2];
            idx2++;
            idx1++;
            fidx++; 
        }
    }    
    for (int idx = 0; idx < fidx; idx++)
    {
        cout<<farr[idx]<<" ";
    }
    cout<<endl;
    return 0;
}