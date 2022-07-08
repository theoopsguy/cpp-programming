#include <iostream>
#include <string>
using namespace std;

string printIncDec(int number)
{
    string str;
    
    if (number == 1)
    {
        return "1\n1";
    }
    
    str = to_string(number) + "\n" + printIncDec(number - 1) + "\n" + to_string(number);
    
    return str;
    
}

int main()
{
    int number;

    cin >> number;

    cout << printIncDec(number);

    return 0;

}
