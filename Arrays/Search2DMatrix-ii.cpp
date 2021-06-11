#include<iostream>
#include<vector>
using namespace std;

//https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int col = matrix[0].size() - 1;
        int row = 0;
        int rows = matrix.size();
        
        while (row < rows && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }

            else{

                if (matrix[row][col] < target)
                {
                    row++;
                }

                else
                {
                    col--;
                }
            }
        }

    return false;    

    }
};