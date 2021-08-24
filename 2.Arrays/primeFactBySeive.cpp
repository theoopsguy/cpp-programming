#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int *arr = new int [n];

    for (int i = 1; i <= n; i++)
        arr[i] = i;

for (int currIdx = 2; currIdx *currIdx <= n; currIdx++){
    int spf = currIdx;
    for (int idx = currIdx*currIdx; idx <= n; idx += currIdx)
    {
        if(arr[idx] == idx)
        arr[idx] = spf;
    }
}

int where = n;

while(where != 1)
{
    cout<<arr[where]<<" ";
    where = where/arr[where];
}

return 0;
}