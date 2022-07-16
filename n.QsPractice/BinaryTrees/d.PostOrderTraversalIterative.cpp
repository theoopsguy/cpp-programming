// https://leetcode.com/problems/binary-tree-postorder-traversal/

// TC: O(n)
// SC: O(2n)         
// Using 2 stacks
/* Basically in postorder traversal the order is left -> right -> root, we just need to push the 
values in stack in reverse order i.e. root->right->left. */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);

        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            if (node->left)
                st1.push(node->left)
            if (node->right)
                st1.push(node->right)
        }

        while (!st2.empty()) {
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
    }
};

// Using single stack
// TC: O(2n)    // We keep adding and then retrieving while comming back
// SC: O(n)     // we don't consider the ans vector in which ans is returned

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        
        TreeNode* curr = root;
        stack<TreeNode*> st;

        while (curr || !st.empty()) {
            if(curr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* temp = st.top()->right;
                if (temp) {
                    curr = temp;
                }
                else {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
            }
        }
        return ans;
    }
};
