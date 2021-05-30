#include<iostream>
using namespace std;
class RationalNo
{
private:
    int num, den;
public:
    RationalNo (int p = 0, int q = 1)
    {
        num = p;
        if (q != 0)
        den = q;
    }
    friend RationalNo operator+ (RationalNo r1, RationalNo r2);
    friend void operator<< (ostream &out, RationalNo &r);
};
int lcm(int r1den, int r2den)
{
    int n1=r1den;                //storing nos. in temporary variables
    int n2=r2den;
    while(n1!=n2)
    {
        if(n1>n2)
        n1=n1-n2;
        
        else
        n2=n2-n1;
    }
    
    return (r1den*r2den)/n1;
}
RationalNo operator+ (RationalNo r1, RationalNo r2)
{
    RationalNo r3;
    r3.den = lcm(r1.den, r2.den);
    r3.num = ((r3.den / r1.den) * r1.num) + ((r3.den / r2.den) * r2.num);
    return r3;
}

void operator<< (ostream &out, RationalNo &r)
{
    cout<<r.num<<"/"<<r.den<<endl;
}

int main()
{
    int num1, den1, num2, den2;
    cin>>num1>>den1>>num2>>den2;
    RationalNo n1(num1, den1);
    RationalNo n2(num2, den2);
    
    RationalNo n3 = n1 + n2;

    cout<<n3;
    
}