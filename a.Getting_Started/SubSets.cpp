#include <iostream>
#include <cmath>
using namespace std;

int binary (int no)
{                           //Converting current iteration to binary
    int binary = 0;
    int ctr = 0;

    while (no)
    {
        int divisor = pow (10, ctr);

        binary +=  (no % 2) * divisor;

        no /= 2;
        ctr++;
    }

    return binary;

}

int main()
{
    int number;

    cin>>number;

    int *arr = new int [number];

    for (int idx = 0; idx < number; idx++)
    {
        cin>>arr[idx];
    }

    int limit = pow (2, number);

    for (int count = 0; count < limit; count++)
    {                                      
        //Printing at 1's and not printing at 0's in binary version of that iteration
        
        int countBinary = binary(count);
        int digits = number;

        for (int idx = 0; idx < number; idx++)
        {
            int divisor = pow (10, (digits - 1));
            int check = countBinary / divisor;

            if (check == 1)
            {
                cout<<arr[idx]<<"\t";
            }

            else
            {
                cout<<"-\t";
            }
            
            countBinary %= divisor;
            digits--;
        }

        cout<<endl;
    }

return 0;

}