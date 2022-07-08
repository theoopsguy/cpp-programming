#include <iostream>
using namespace std;

void printDecreasing(int number)
{
    if (number==0)
    {
        return;
    }

    cout<<number<<endl;
    number--;

    printDecreasing(number);
}

int main()
{
    int number;

    cin >> number;

    printDecreasing(number);

    return 0;
    
}
