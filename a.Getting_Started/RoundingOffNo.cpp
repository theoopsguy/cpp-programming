#include <iostream>
using namespace std;

int approx (double num)
    {
        int tempNum = num*10;
        int tempCheck = tempNum%10;
        int roundNum;
            
        if(num>0)
        {
            if(tempCheck>=5)
            {
                roundNum = num;
                roundNum++;
            }
            else
            {
                roundNum = num;
            }
            return roundNum;
        }
        else if(num<0)
        {
            num = -(num);
            tempNum = num*10;
            tempCheck = tempNum%10;
            if(tempCheck>=5)
            {
                roundNum = num;
                roundNum--;
            }
            else
            {
                roundNum = num;
            }
            return roundNum;
        }
        else
            return 0;
    }

    int main()
    {
        int n;
        cin>>n;
        cout<<approx(n);
    }