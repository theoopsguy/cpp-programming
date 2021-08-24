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

int main()
{
    int number; 
    
    cin>>number;

    cout<<factorial(number);

    return 0;

}