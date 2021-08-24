#include <iostream>
using namespace std;

/*
sr = source row
sc = source column
dr = destination row
dc = destination column
*/

void printMazePaths(int sr, int sc, int dr, int dc, string psf)
{
    if (sr == dr && sc == dc)
    {
        cout<<psf<<endl;

        return;
    }

    if (sc <= dc)
    {
        printMazePaths(sr, sc+1, dr, dc, psf + "h");
    }

    if (sr <= dr)
    {
        printMazePaths(sr+1, sc, dr, dc, psf + "v");
    }
}

int main()
{
    int rows, cols;

    cin >> rows >> cols;

    printMazePaths(1, 1, rows, cols, "");

    return 0;

}