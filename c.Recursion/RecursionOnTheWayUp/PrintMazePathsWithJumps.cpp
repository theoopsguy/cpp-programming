#include<iostream>
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
    
    for (int horizontal = 1; horizontal <= dc - sc; horizontal++)
    {
        printMazePaths(sr, sc+horizontal, dr, dc, psf + "h" + to_string(horizontal));
    }

    for (int vertical = 1; vertical <= dr - sr; vertical++)
    {
        printMazePaths(sr+vertical, sc, dr, dc, psf + "v" + to_string(vertical));
    }

    for (int diagonal = 1; diagonal <= dc - sc && diagonal <= dr - sr; diagonal++)
    {
        printMazePaths(sr+diagonal, sc+diagonal, dr, dc, psf + "d" + to_string(diagonal));
    }
}

int main() 
{
    int rows, cols ;

    cin>>rows>>cols;

    printMazePaths(1, 1, rows, cols, "");

    return 0;

}