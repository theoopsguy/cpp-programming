#include <iostream>
using namespace std;
class complex{
private:
    int real, img;
public:
    complex (int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }
    friend ostream & operator<< (ostream &out, complex &c);
};
ostream & operator<< (ostream &out, complex &c)
{
    cout<<c.real<<" + i"<<c.img;
    return out;
}
int main()
{
    complex c1(15, 10);
    cout<<c1;
}