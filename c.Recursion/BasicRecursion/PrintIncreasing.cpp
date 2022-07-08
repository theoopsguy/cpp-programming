#include<iostream>
using namespace std;

void printIncreasing(int number)
{
    if (number == 0)
    {
        return;
    }

    printIncreasing(number - 1);

    cout<<number<<endl;
}


int main()
{
    int number; 
    
    cin>>number;

    printIncreasing(number);

    return 0;
    
}