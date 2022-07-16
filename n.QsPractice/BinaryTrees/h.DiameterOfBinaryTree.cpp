// https://leetcode.com/problems/diameter-of-binary-tree/

// TC: O(N)
// TC: O(N)     For auxillary stack in recursion

class Solution {
public:
    int l = -1;
    int heightOfTree(TreeNode* root) {
        if (!root)
            return 0;
        int lh = heightOfTree(root->left);
        int rh = heightOfTree(root->right);

        int currL = lh + rh;
        l = currL > l ? currL : l;
        
        return max(lh, rh) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int h = heightOfTree(root);
        return l;
    }
};