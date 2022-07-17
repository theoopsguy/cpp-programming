//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// In level order traversal just add a flag to denote direction of traversal.

// TC: O(N)
// SC: O(N)

//reversing the vector

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 0;  // 0->left-right 1->right-left

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (flag == 1)
                reverse(level.begin(), level.end());
            ans.push_back(level);
            flag = flag == 0 ? 1 : 0;
        }
        return ans;
    }
};

// Pushing directly as reversed

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                int index = (leftToRight) ? i : (size - i - 1);
                level[index] = node->val;
            }
            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};