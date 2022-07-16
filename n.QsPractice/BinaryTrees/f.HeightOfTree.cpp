//https://leetcode.com/problems/maximum-depth-of-binary-tree/

//aka Max depth of binary tree

// TC: O(n)
// SC: O(n)
// Recusive soln:

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return (max(lh, rh) + 1);
    }
};

//Iterative can be to do level order traversal and have a variable which increments when we go left or right,
// and the highest level will be the ans.
// Same complexity.