#include<iostream>
#include<vector>
using namespace std;

//https://leetcode.com/problems/spiral-matrix/

class Solution {
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int rows = matrix.size(), cols = matrix[0].size(), fromRow = 0, tillRow = rows - 1, fromCol = 0, tillCol = cols - 1, pos = 0;
        
        vector<int> order(rows * cols);

        while (fromRow <= tillRow && fromCol <= tillCol) {

            for (int col = fromCol; col <= tillCol; col++) 
            {
                order[pos++] = matrix[fromRow][col];
            }

            if (++fromRow > tillRow) 
            {
                break;
            }

            for (int row = fromRow; row <= tillRow; row++) 
            {
                order[pos++] = matrix[row][tillCol];
            }

            if (--tillCol < fromCol) 
            {
                break;
            }

            for (int col = tillCol; col >= fromCol; col--) 
            {
                order[pos++] = matrix[tillRow][col];
            }

            if (--tillRow < fromRow) 
            {
                break;
            }

            for (int row = tillRow; row >= fromRow; row--) 
            {
                order[pos++] = matrix[row][fromCol];
            }

            if (fromCol++ > tillCol) 
            {
                break;
            }
        }
        
        return order;
        
    }
};