#include<iostream>
using namespace std;

template<class T>
T maxim(T x, T y)
{
    if (x>y)
    return x;
    else
    return y;
    
}

int main()
{
    int a=maxim(7,10);
    cout<<a<<endl;    
    cout<<maxim(7.32f, 90.0f)<<endl;    
    return 0;
}
