#include<iostream>
#include<string>
using namespace std;

string factorial(int number, int &fact)
{
    string str;
    
    if (number == 1)
    {
        string str1 = "1=" + to_string(fact);
        return str1;
    }
    
    fact *= number;
    str = to_string(number) + '*' + factorial (number-1, fact);
    
    return str;
}


int main()
{
    int number; 
    
    cin>>number;

    int fact = 1;

    cout<<factorial(number, fact);

    return 0;

}

