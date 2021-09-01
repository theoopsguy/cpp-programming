#include <iostream>
using namespace std;

/*
5 0 0 0 0 
0 10 0 0 0 
0 0 15 0 0 
0 0 0 20 0 
0 0 0 0 25

this diagonal matrix is being stored in an array with elements: 5 10 15 20 25
we are not storing 0s so as to save memory space and time to process 0 elements.
*/

class diagonalMatrix
{
    private:
        int size;
        int *arr;

    public:
        diagonalMatrix(int n)
        {
            this->size = n;
            this->arr = new int[n];
        }

        void set(int row, int col, int data);

        int get(int row, int col);

        void display();

        ~diagonalMatrix()
        {
            delete []arr;
        }
};

void diagonalMatrix::set(int row, int col, int data)
{
    if (row == col)
        arr[row - 1] = data;
}

int diagonalMatrix::get(int row, int col)
{
    if (row == col)
        return arr[row - 1];
    else
        return 0;
}

void diagonalMatrix::display()
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (row == col)
                cout<<arr[row]<<" ";
            else
                cout<<"0 ";
        }

        cout<<endl;
    }
}

int main()
{
    diagonalMatrix d(5);

    d.set(1, 1, 5);
    d.set(2, 2, 10);
    d.set(3, 3, 15);
    d.set(4, 4, 20);
    d.set(5, 5, 25);

    d.display();
    return 0;
}