#include <iostream>
#include <climits>
using namespace std;

int max(int *arr, int n){
    static int m = INT_MIN;
    
    if (n == 0)
    {
        return m; 
    }

    int temp = arr[0];

    if (m < temp)
    {
        m = temp;
    }

    max(arr+1, n-1);
    
    return m;
    
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    int p = max(arr, n);
    cout << p << endl;
}