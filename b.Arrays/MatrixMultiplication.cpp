#include<iostream>
using namespace std;

int** matrix (int **arr, int rows, int cols)
{
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

int main()
{
    int rows1, cols1;

    cin>>rows1>>cols1;
    
    int **arr1 = new int *[rows1];
    
    arr1 = matrix (arr1, rows1, cols1);     //Creating 2d array
    
    arr1 = input (arr1, rows1, cols1);      //Inputting elements in array
    
    int rows2, cols2;

    cin>>rows2>>cols2;
    
    int **arr2 = new int *[rows2];
    
    arr2 = matrix (arr2, rows2, cols2);     //Creating 2d array
    
    arr2 = input (arr2, rows2, cols2);      //Inputting elements in array
    
    if (cols1 == rows2)
    {        
        for (int rowidx = 0; rowidx < rows1; rowidx++)
        {
            for (int colidx = 0; colidx < cols2; colidx++)
            {
                int mult = 0;
                
                for (int posidx = 0; posidx < cols1; posidx++)
                {    
                    mult += arr1[rowidx][posidx] * arr2[posidx][colidx];
                }
            
                cout<<mult<<" ";
            }

        cout<<endl;

        }
    }   
    
    else
    {
        cout<<"Invalid input";
    }

return 0;

}