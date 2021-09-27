#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int *rse = new int[n], *lse = new int[n];
        
        stack<int> indices;
        
        for (int idx = 0; idx < n; idx++)
        {
            int curEl = heights[idx];
            
            while (!indices.empty() && heights[indices.top()] >= curEl)
            {
                indices.pop();
            }
            
            if (indices.empty())
            {
                lse[idx] = 0;
            }
            
            else
            {
                lse[idx] = indices.top() + 1;
            }
            
            indices.push(idx);
        }
        
        while (!indices.empty())
            indices.pop();  //empty the stack to be reused.
        
        for (int idx = n - 1; idx >= 0; idx--)
        {
            int curEl = heights[idx];
            
            while (!indices.empty() && heights[indices.top()] >= curEl)
            {
                indices.pop();
            }
            
            if (indices.empty())
            {
                rse[idx] = n - 1;
            }
            
            else
            {
                rse[idx] = indices.top() - 1;
            }
            
            indices.push(idx);
        }       

        int maxA = 0;
        
        for (int idx = 0; idx < n; idx++)
        {
            maxA = max(maxA, heights[idx] * (rse[idx] - lse[idx] + 1));
        }
        
        return maxA;
    }
};