#include<iostream>
using namespace std;

//e^x = 1 + x/1! + x^2/2! + x^3/3! + x^4/4! + _ _ _ upto n terms.

double e(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    static float var = 1, fact = 1;
    double temp = e(x, n-1);
    var *= x;
    fact *= n;
    return temp + var/fact;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << e(x, n);
    return 0;
}