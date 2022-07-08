#include <iostream>
using namespace std;

//Sparse Matrix is one in which most of the elements are 0 with only a few non-zero elements.
/*
Example Input:
0 0 2
2 1 5
3 0 3
4 3 9
Corresponding Output:
2 0 0 0 0 
0 0 0 0 0 
0 5 0 0 0 
3 0 0 0 0 
0 0 0 9 0 
*/
class Element
{
public:
    int row, col, data;
};

class Sparse
{
private:
    int rows, cols, nums;
    Element *ele;
public:
    Sparse(int m, int n, int num)
    {
        this->rows = m;
        this->cols = n;
        this->nums = num;
        ele = new Element[this->nums];
    }
    void read()
    {
        cout<<"Enter non-zero elements:\n";
        for (int idx = 0; idx < nums; idx++)
        {
            cin>>ele[idx].row>>ele[idx].col>>ele[idx].data;
        }
    }
    void display()
    {
        int denote = 0;
        for (int rowcnt = 0; rowcnt < rows; rowcnt++)
        {
            for (int colcnt = 0; colcnt < cols; colcnt++)
            {
                if (ele[denote].row == rowcnt && ele[denote].col == colcnt)
                {
                    cout<<ele[denote].data<<" ";
                    denote++;
                }
                else
                    cout<<"0 ";
            }
            cout<<endl;
        }
    }
    ~Sparse()
    {
        delete []ele;
    }
};

int main()
{
    Sparse s(5, 5, 4);
    s.read();
    s.display();
    return 0;
}