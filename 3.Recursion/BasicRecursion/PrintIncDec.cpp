#include<iostream>
using namespace std;

void printIncDec(int number)
{
    if (number == 0)
    {
        return;
    }
    
    cout<<number<<endl;

    printIncDec(number - 1);

    cout<<number<<endl;
}

int main()
{
    int number; 
    
    cin>>number;

    printIncDec(number);
    
    return 0;
    
}