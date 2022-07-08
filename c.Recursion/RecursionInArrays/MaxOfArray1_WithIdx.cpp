#include <iostream>
#include <climits>
using namespace std;

int max(int *arr, int idx, int n){
    static int m = INT_MIN;
    
    if (idx == n)
    {
        return m; 
    }

    int temp = arr[idx];

    if (m < temp)
    {
        m = temp;
    }

    max(arr, idx+1, n);
    
    return m;
    
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    int p = max(arr, 0, n);
    cout << p << endl;
}