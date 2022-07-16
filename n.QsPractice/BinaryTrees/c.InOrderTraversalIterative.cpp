//https://leetcode.com/problems/binary-tree-inorder-traversal/

// TC: O(n)
// SC: O(n)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        
        while(!st.empty() || node) {
            if (node) {
                st.push(node);
                node = node->left;
            }
            else {
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};