//https://www.lintcode.com/problem/878/

// TC: O(N) //O(H) leftBoundary + O(H) rightboundary + O(N) leafNodes
// SC: O(N) //auxilary recursion stack

class Solution {
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
    vector<int> ans;
    void leftBoundary(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            return;
        }
        ans.push_back(root->val);
        if (root->left) {
            leftBoundary(root->left);
        }
        else {
            leftBoundary(root->right);
        }
    }
    void leafNodes(TreeNode* root) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            ans.push_back(root->val);
            return;
        }
        leafNodes(root->left);
        leafNodes(root->right);
    }
    void rightBoundary(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            return;
        }
        if (root->right) {
            rightBoundary(root->right);
        }
        else {
            rightBoundary(root->left);
        }
        ans.push_back(root->val);
    }
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        if (!root)
            return ans;
        if (!(!root->left && !root->right))
            ans.push_back(root->val);
        leftBoundary(root->left);
        leafNodes(root);
        rightBoundary(root->right);
        return ans;
    }
};