#include <iostream>
#include <string>
using namespace std;

string printDecreasing(int number)
{
    string str;
    
    if (number == 0)
    {
        return str;
    }
    
    str = to_string(number) + '\n' + printDecreasing(number - 1);

    return str;
    
}

int main()
{
    int number;

    cin >> number;

    cout<<printDecreasing(number);
    
    return 0;

}
