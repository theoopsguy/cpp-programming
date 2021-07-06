#include<iostream>
using namespace std;

int power(int x,int n){
    
    if (n == 0)
    {
        return 1;
    }
    
    if (n%2 == 0)
    {
        x = power(x*x, n/2);
    }
    else
    {
        x *= power(x*x, (n-1)/2); 
    }
    
    return x;
}


int main(){
    int n,x; 
    cin>>x>>n;
    cout<<power(x,n);
}
