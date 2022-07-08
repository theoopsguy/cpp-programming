#include<iostream>
#include<climits>
using namespace std;

int** matrix (int **arr, int rows, int cols)
{
    arr = new int * [rows];

    for (int row = 0; row < rows; row++)
    {
        arr[row] = new int [cols];
    } 
    
    return arr;
}

int** input (int **arr, int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cin>>arr[row][col];
        }
    }

    return arr;
}

void display (int **arr, int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout<<arr[row][col]<<" ";
        }
        
        cout<<endl;
    }
}

void saddlepoint (int **arr, int rows, int cols)
{
    int row = 0;
    int minrow = INT_MAX;
    int maxcol = INT_MIN;
    int colidx, rowidx;
    int whichcol, whichrow;
    while(1)
    {
    for (int col = 0; col < cols; col++)
    {
        if (arr[row][col] < minrow)
        {
            minrow = arr[row][col];
            whichcol = col;
            whichrow = row;
        }
    }

    for (row = 0; row < rows; row++)
    {
        if (arr[row][whichcol] >= maxcol)
        {
            maxcol = arr[row][whichcol];
        }
    }
    if (arr[whichrow][whichcol] == maxcol)
        break;

    }

    if (arr[whichrow][whichcol] == maxcol)
        cout<<arr[whichrow][whichcol];
    else
        cout<<"Invalid Input";
}

int main()
{
    int rows, cols;

    cin>>rows>>cols;

    int **arr = matrix (arr, rows, cols);

    arr = input (arr, rows, cols);

    saddlepoint (arr, rows, cols); 
}