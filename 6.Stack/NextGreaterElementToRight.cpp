#include <iostream>
#include <stack>
using namespace std;

int * nge(int size, int *arr)
{
    stack<int> elements;
    int *ngetr = new int[size];

    for (int idx = 0; idx < size; idx++)
    {
        while (!elements.empty() && arr[elements.top()] < arr[idx])
        {
            ngetr[elements.top()] = arr[idx];
            elements.pop();
        }

        elements.push(idx);
    }

    while (!elements.empty())
    {
        ngetr[elements.top()] = -1;
        elements.pop();
    }
    return ngetr;
}

int main()
{
    int size;
    cin>>size;
    
    int *arr = new int[size];
    
    for (int idx = 0; idx < size; idx++)
    {
        cin>>arr[idx];
    }
    
    int *ngetr = nge(size, arr);
    
    for (int idx = 0; idx < size; idx++)
    {
        cout<<ngetr[idx]<<endl;
    }

    return 0;
}