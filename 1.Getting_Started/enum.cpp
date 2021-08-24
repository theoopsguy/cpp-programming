#include<iostream>
using namespace std;
enum dept {cs, it, ece, civil};
enum day {mon,tue,wed};
int main()
{
dept d;
day da;
d=ece;
da=tue;
cout<<d<<endl<<da;
return 0;
}