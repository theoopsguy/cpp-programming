#include <iostream>
using namespace std;

void add(int size1, int *arr1, int size2, int *arr2)
{
    int maxsize = size1 > size2 ? size1 : size2;
    int *arr3 = new int [maxsize + 1];
    int carry = 0;
    int firstidx = size1 - 1;
    int secondidx = size2 - 1;

    for (int idx = maxsize; idx >= 0; idx--)
    {
        int firstele = arr1[firstidx];
        int secondele = arr2[secondidx];
        if (firstidx >= 0)
        firstidx--;
        if (secondidx >= 0)
        secondidx--;
        int sum = firstele + secondele + carry;

        if (sum >= 10)
        {
            carry = sum/10;
            arr3[idx] = sum % 10;
        }
        else
        {
            arr3[idx] = sum;
            carry = 0;
        }
    }

    int i;
    if (arr3[0] == 0)
        i = 1;
    else
        i = 0;

    while (i <= maxsize){
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
    
    add(n1, arr1, n2, arr2);


	return 0;
}