#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/n-queens-ii/

class Solution {

public:

    int noOfQueens = 0;

    bool clearToPlace(int row, int col, int n, vector<string> &maze)
    {
        for (int ro = row - 1; ro >= 0; ro--)
        {
            if (maze[ro][col] == 'Q')
            {
                return false;
            }
        }

        for (int ro = row - 1, co = col - 1; ro >= 0 && co >= 0; ro--, co--)
        {
            if (maze[ro][co] == 'Q')
            {
                return false;
            }
        }

        for (int ro = row - 1, co = col + 1; ro >= 0 && co < n; ro--, co++)
        {
            if (maze[ro][co] == 'Q')
            {
                return false;
            }
        }

        return true;
    }
    
    void queens(int n, int row, vector<string> &maze)     
    {
        if (row == n)
        {
            noOfQueens++;

            return;
        }
        
        for (int col = 0; col < n; col++)
        {
            if (clearToPlace(row, col, n, maze))
            {
                maze[row][col] = 'Q';

                queens (n, row+1, maze);

                maze[row][col] = '.';
            }
        }
    }  
    
    int totalNQueens(int n) 
    {
        vector<string> maze(n, string(n, '.'));

        queens(n, 0, maze);

        return noOfQueens;

    }
};