#include <iostream>
using namespace std;

int** matrix (int **arr, int size, int row, int col)
{
    arr = new int *[size];

    for (int row = 0; row < size; row++)
    {
        arr[row] = new int [size];

        for (int col = 0; col < size; col++)
        {
            arr[row][col] = 0;
        }
    }

    return arr;
}

void printKnightsTour(int** chess, int row, int col, int size, int idx)
{
    if (idx == size*size)
    {
        chess[row][col] = idx;

        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                cout<<chess[row][col]<<" ";
            }

            cout<<endl;
        }

        cout<<endl;

        chess[row][col] = 0;

        return;
    }

    chess[row][col] = idx;

    if (row-2 >= 0 && col+1 < size && chess[row-2][col+1] == 0)
    {
        printKnightsTour(chess, row-2, col+1, size, idx+1);
    }

    if (row-1 >= 0 && col+2 < size && chess[row-1][col+2] == 0)
    {
        printKnightsTour(chess, row-1, col+2, size, idx+1);
    }

    if (row+1 < size && col+2 < size && chess[row+1][col+2] == 0)
    {
        printKnightsTour(chess, row+1, col+2, size, idx+1);
    }

    if (row+2 < size && col+1 < size && chess[row+2][col+1] == 0)
    {
        printKnightsTour(chess, row+2, col+1, size, idx+1);
    }

    if (row+2 < size && col-1 >= 0 && chess[row+2][col-1] == 0)
    {
        printKnightsTour(chess, row+2, col-1, size, idx+1);
    }

    if (row+1 < size && col-2 >= 0 && chess[row+1][col-2] == 0)
    {
        printKnightsTour(chess, row+1, col-2, size, idx+1);
    }

    if (row-1 >= 0 && col-2 >= 0 && chess[row-1][col-2] == 0)
    {
        printKnightsTour(chess, row-1, col-2, size, idx+1);
    }

    if (row-2 >= 0 && col-1 >= 0 && chess[row-2][col-1] == 0)
    {
        printKnightsTour(chess, row-2, col-1, size, idx+1);
    }
    
    chess[row][col] = 0;
}

int main()
{
    int size;

    cin>>size;

    int row, col;

    cin>>row>>col;

    int **arr = matrix(arr, size, row, col);

    printKnightsTour(arr, row, col, size, 1);

    return 0;

}