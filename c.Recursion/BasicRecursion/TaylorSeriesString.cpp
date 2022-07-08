#include<iostream>
using namespace std;

//e^x = 1 + x/1! + x^2/2! + x^3/3! + x^4/4! + _ _ _ upto n terms.

string e(int x, int n)
{
    if (n == 0)
    {
        string str = to_string(1) + "+";
        return str;
    }
    static int var = 1, fact = 1;
    string str = e (x, n-1);
    var *= x, fact *= n;
    str += to_string(var) + "/" + to_string(fact) + "+";
    return str;
}

int main()
{
    int x, n;
    cin>>x>>n;
    cout<<e(x, n);
    return 0;
}