//https://leetcode.com/problems/balanced-binary-tree/submissions/

// TC: O(n^2)   // O(n) for finding height x O(n) for finding balanced or not

class Solution {
public:
    int heightOfTree(TreeNode* root) {
        if (!root)
            return 0;
        int lh = heightOfTree(root->left);
        int rh = heightOfTree(root->right);

        return max(lh, rh) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        
        bool ans = abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1 ? true : false;
        
        if (!l || !r || !ans)
            return false;
        else
            return true;
    }
};

// TC: O(n)
// Finding height and balance or not in the same recursive traversal.

class Solution {
public:
    int heightOfTree(TreeNode* root) {
        if (!root)
            return 0;
        int lh = heightOfTree(root->left);
        int rh = heightOfTree(root->right);
        
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1)
            return -1;
        else
            return max(lh, rh) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        int ans = heightOfTree(root);
        if (ans == -1)
            return false;
        else
            return true;
    }
};