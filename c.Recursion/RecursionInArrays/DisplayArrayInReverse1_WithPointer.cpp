#include <iostream>
using namespace std;

void display(int arr[], int n){
    if (n == 0)
    {
        return;
    }
    cout<<arr[n-1]<<endl;
    display(arr, n-1);
    
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    display(arr, n);
}