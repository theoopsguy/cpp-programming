#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/sudoku-solver/

class Solution 
{
public:
   
    bool solvePuzzle(vector<vector<char>>& board) 
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                   for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isValid(board, row, col, ch))
                        {
                            board[row][col] = ch;
                            
                            if (solvePuzzle(board))
                            {
                                return true;
                            }

                            else
                            {
                                board[row][col] = '.';
                            }
                        }
                    } 

                    return false;
                }
            }
        }

        return true;
    } 
    
    bool isValid(vector<vector<char>>& board, int row, int col, char ch)
    {
        for (int idx = 0; idx < 9; idx++)
        {
            if (board[row][idx] == ch)
            {
                return false;
            }
            
            else if (board[idx][col] == ch)
            {
                return false;
            }
            
            else if (board[3 * (row / 3) + idx / 3][3 * (col / 3) + idx % 3] == ch) 
            {
                return false;           //checking the small boxes
            }
        }

        return true;
    }
    
    void solveSudoku (vector<vector<char>>& board) 
    {
        solvePuzzle (board);
    }
};