#include <iostream>
using namespace std;

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
    
    ~Sparse()
    {
        delete []ele;
    }

    Sparse operator+(Sparse &s);

    //inseration and extraction operator function overloading
    friend istream & operator>>(istream &is, Sparse &s);
    friend ostream & operator<<(ostream &os, Sparse &s);

};

Sparse Sparse :: operator+(Sparse &s)
{
    int ptr1 = 0, ptr2 = 0, ptr3 = 0;

    if (rows != s.rows || cols != s.cols)
        return Sparse(0,0,0);
    //dimensions of the 2 matrices to be added must be same

    Sparse *sum = new Sparse (rows, cols, nums + s.nums); //New matrix created with maximum size possible

    while (ptr1 < nums && ptr2 < s.nums)
    {
        if (ele[ptr1].row < s.ele[ptr2].row)
            sum->ele[ptr3++] = ele[ptr1++];
        else if (ele[ptr1].row > s.ele[ptr2].row)
            sum->ele[ptr3++] = s.ele[ptr2++];
        else
        {
            if (ele[ptr1].col < s.ele[ptr2].col)
                sum->ele[ptr3++] = ele[ptr1++];
            else if (ele[ptr1].col > s.ele[ptr2].col)
                sum->ele[ptr3++] = s.ele[ptr2++];
            else
            {
                sum->ele[ptr3] = ele[ptr1];
                sum->ele[ptr3++].data = ele[ptr1++].data + s.ele[ptr2++].data;
            }
        }

    }

    for (; ptr1 < nums; ptr1++)
        sum->ele[ptr3++] = ele[ptr1];
    for (; ptr2 < s.nums; ptr2++)
        sum->ele[ptr3++] = s.ele[ptr2];
    
    sum->nums = ptr3;
    return *sum;

}

    istream &operator >>(istream &is, Sparse &s)
    {
        cout<<"Enter non-zero elements:\n";
        for (int idx = 0; idx < s.nums; idx++)
        {
            cin>>s.ele[idx].row>>s.ele[idx].col>>s.ele[idx].data;
        }
        return is;
    }
    ostream &operator <<(ostream &os, Sparse &s)
    {
        int denote = 0;
        for (int rowcnt = 0; rowcnt < s.rows; rowcnt++)
        {
            for (int colcnt = 0; colcnt < s.cols; colcnt++)
            {
                if (s.ele[denote].row == rowcnt && s.ele[denote].col == colcnt)
                {
                    cout<<s.ele[denote].data<<" ";
                    denote++;
                }
                else
                    cout<<"0 ";
            }
            cout<<endl;
        }
        return os;
    }

int main()
{
    Sparse s1(5, 5, 4);
    Sparse s2(5, 5, 4);
    
    cout<<"Input First Matrix\n";
    cin>>s1;
    cout<<"Input Second Matrix\n";
    cin>>s2;

    Sparse sum = s1+s2;

    cout<<"First Matrix\n"<<s1<<"Second Matrix\n"<<s2<<"Sum\n"<<sum;
    return 0;
}
/*
Test Input:
First Matrix:
0 1 4
2 1 6
3 3 5
4 4 10
Second Matrix:
2 1 4
3 3 1
4 1 7   
4 4 12
Output Sum:
0 4 0 0 0 
0 0 0 0 0 
0 10 0 0 0 
0 0 0 6 0 
0 7 0 0 22
*/