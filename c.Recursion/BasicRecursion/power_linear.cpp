#include<iostream>
using namespace std;

int power(int x,int n){
    
    if (n == 0)
    {
        return 1;
    }
    
    x *= power(x, n-1);
    
    return x;
}


int main(){
    int n,x; 
    cin>>x>>n;
    cout<<power(x,n);
    return 0;
}
