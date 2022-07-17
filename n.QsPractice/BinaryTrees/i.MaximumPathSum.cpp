//https://leetcode.com/problems/binary-tree-maximum-path-sum/+

// TC: O(N)
// SC: O(N)

class Solution {
public:
    int mSum;   
    int findSum (TreeNode* root) {
        if (!root)
            return 0;
        int ls = max(0, findSum(root->left));
        int rs = max(0, findSum(root->right));

        mSum = max(mSum, ls + rs + root->val);
        return max(ls, rs) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        mSum = INT_MIN;
        findSum(root);
        return mSum;
    }
};