#include<iostream>
using namespace std;
int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int f = fibo(n-2) + fibo(n-1);
    cout<<f<<" ";
    return f;
}
int main()
{
    int n;
    cin>>n;
    cout<<fibo(n);
}