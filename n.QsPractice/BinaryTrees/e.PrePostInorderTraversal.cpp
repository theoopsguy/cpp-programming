// Preorder, postorder, inorder traversal together in one program.
// TC: O(3n) = O(n)     //Visiting each node three times for all three traversals
// SC: O(3n) = O(n)

vector<int> preOrder;
vector<int> postOrder;
vector<int> inOrder;

if (!root)
    return preOrder;

stack<pair<TreeNode*, int>> st; // node, num
st.push({root, 1});

while (!st.empty()) {
    pair<TreeNode*, int> p = st.top();
    st.pop();

    TreeNode* node = p.first;
    int num = p.second;
    
    if (num == 1) {
        preOrder.push_back(node->val);
        st.push({node, num+1});
        if (node->left)
            st.push({node->left, 1});
    }
    else if (num == 2) {
        inOrder.push_back(node->val);
        st.push({node, num+1});
        if (node->right)
            st.push({node->right, 1});
    }
    else {
        postOrder.push_back(node->val);
    }
}

return preOrder;
// return inOrder;
// return postOrder;