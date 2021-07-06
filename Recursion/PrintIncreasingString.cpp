#include <iostream>
#include <string>
using namespace std;

string printIncreasing(int n)
{
    string str;
    
    if (n == 0)
    {
        return str;
    }
    
    str = printIncreasing(n - 1);
    
    str.append(to_string(n));
    
    str += '\n';

    return str;
    
}

int main()
{
    int n;

    cin >> n;

    cout << printIncreasing(n);

    return 0;
}
