//https://leetcode.com/problems/binary-tree-preorder-traversal/

// TC: O(n)
// SC: O(n)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
            ans.push_back(node->val);
        }
        return ans;
    }
};