#include<iostream>
using namespace std;

int factorial(int number)
{
    if (number == 1)
    {
        return number;
    }
    
    return number * factorial (number - 1);
}

int c(int n, int r)
{
    return (factorial(n) / factorial(r)) / factorial(n-r);
}

int main()
{
    int n, r; 
    
    cin>>n>>r;

    cout<<c(n, r);

    return 0;

}