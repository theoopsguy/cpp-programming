#include <iostream>
using namespace std;

class lowerTriangle
{
    private:
        int size;
        int *arr;

    public:
        lowerTriangle(int n)
        {
            this->size = n;
            this->arr = new int[n*(n+1)/2];     
            
            //in a lower triangular matrix no. of nonzero elements is n(n+1)/2
        }

        void set(int row, int col, int data);

        int get(int row, int col);

        int getDimension()
        {
            return size;
        }

        void display();

        ~lowerTriangle()
        {
            delete []arr;
        }
};

void lowerTriangle::set(int row, int col, int data)
{
    if (row >= col)
        arr[row*(row-1)/2 + col - 1] = data;
        //index of ele M[5][4] in our array will be (1 + 2 + 3 + 4) + 3 = 13
}

int lowerTriangle::get(int row, int col)
{
    if (row >= col)
        return arr[row*(row - 1)/2 + col - 1];
    else
        return 0;
}

void lowerTriangle::display()
{
    for (int row = 1; row <= size; row++)
    {
        for (int col = 1; col <= size; col++)
        {
            if (row >= col)
                cout<<arr[row*(row-1)/2 + col - 1]<<" ";
            else
                cout<<"0 ";
        }

        cout<<endl;
    }
}

int main()
{
    int size;
    cout<<"Enter Dimensions: \n";
    cin>>size;
    lowerTriangle lt(size);
    int data;
    cout<<"Enter all the elements: \n";
    for (int row = 1; row <= size; row++)
    {
        for (int col = 1; col <= size; col++)
        {
            cin>>data;
            lt.set(row, col, data);
        }
    }
    lt.display();
    return 0;
}