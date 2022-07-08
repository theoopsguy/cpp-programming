#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/valid-sudoku/

class Solution 
{

public:

    bool isValid (vector<vector<char>>& board, int row, int col, char ch)
    {
        int cnt=0;

        for(int colidx = 0; colidx < 9; colidx++)
        {
            if(board[row][colidx] == ch)
            {
                cnt++;
            }

            if(cnt==2) 
            {
                return false;
            }
        }
        
        cnt =0;

        for(int rowidx = 0; rowidx < 9; rowidx++)
        {
            if(board[rowidx][col] == ch)
            {
                cnt++;
            }

            if(cnt == 2) 
            {
                return false;
            }
        }
        
        row -= row%3;
        col -= col%3;

        cnt=0;

        for(int rowidx = 0; rowidx < 3; rowidx++)
        {
            for(int colidx = 0; colidx < 3; colidx++)
            {
                if(board[rowidx + row][colidx + col] == ch)
                {
                    cnt++;
                }

                if(cnt == 2) 
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool checkSudoku(vector<vector<char>>& board, int row, int col) 
    {
        if (row == 8 && col == 8)
        {
            return true;
        }
                
        if (board[row][col]!='.')
        {
            if (isValid (board, row, col, board[row][col]))
            {
                if (col < 8)
                {
                    if (checkSudoku(board, row, col+1))
                    {
                        return true;
                    }
                            
                    else
                    {
                        return false;
                    }        

                }
                    
                else
                {
                    if (checkSudoku(board, row+1, 0))
                    {
                        return true;
                    }
                        
                    else
                    {
                        return false;
                    }
                }
            } 
               
            else 
            {
                return false;
            }
        } 

        else 
        {
            if (col < 8)
            {
                if (checkSudoku(board, row, col+1))
                {
                    return true;
                }
            
                else
                {
                    return false;
                }
            }
                    
            else
            {
                if (checkSudoku(board, row+1, 0))
                {
                    return true;
                }    
                
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        if (checkSudoku(board, 0, 0))
        {
            return true;
        }

        else
        {
            return false;
        }
    }
};