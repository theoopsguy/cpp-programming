#include <iostream>
using namespace std;

void diff(int size1, int *arr1, int size2, int *arr2)
{
    int *arr3 = new int [size2];
    int borrow = 0;
    int firstidx = size1 - 1;
    int secondidx = size2 - 1;

    for (int idx = size2 - 1; idx >= 0; idx--)
    {
        int firstele = arr1[firstidx];
        int secondele = arr2[secondidx];
        if (firstidx >= 0)
        firstidx--;
        if (secondidx >= 0)
        secondidx--;

        int diff = secondele - borrow - firstele;

        if (diff >= 0)
        {
            borrow = 0;
            arr3[idx] = diff;
            
        }

        else
        {
            diff += 10;
            borrow = 1;
            arr3[idx] = diff;
        }
    }
    int i;
    if (arr3[0] == 0)
        i = 1;
    else
        i = 0;

    while (i < size2)
    {
        cout<<arr3[i]<<endl;
        i++;
    }
}

int main() {
    int n1, n2;
    cin>>n1;
    int *arr1 = new int[n1];
    for (int i = 0; i < n1; i++)
    {
        cin>>arr1[i];
    }
    
    cin>>n2;
    int *arr2 = new int [n2];
    for (int i = 0; i < n2; i++)
    {
        cin>>arr2[i];
    }
    
    diff(n1, arr1, n2, arr2);


	return 0;
}