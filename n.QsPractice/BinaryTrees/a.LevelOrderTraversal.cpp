//https://leetcode.com/problems/binary-tree-level-order-traversal

// TC: O(n) each node is one iteration in the queue
// SC: O(n) vector and queue will be max of n size

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        
        return ans;
    }
};