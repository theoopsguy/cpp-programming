#include <iostream>
using namespace std;

void printStairPaths(int stairs, string psf)
{
    if (stairs == 0)
    {
        cout << psf << endl;

        return;
    }

    if (stairs >= 1)
    {
        printStairPaths(stairs-1, psf + "1");
    }

    if (stairs >= 2)
    {
        printStairPaths(stairs-2, psf + "2");
    }

    if (stairs >= 3)
    {
        printStairPaths(stairs-3, psf + "3");
    }
}

int main()
{
    int stairs;

    cin >> stairs;

    printStairPaths(stairs, "");

    return 0;

}