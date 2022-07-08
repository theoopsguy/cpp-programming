#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;     
    /*would work fine even without this base case, this is just to handle the edge case when NULL is passed to the function.*/ 

    cout << root->data << ": ";

    for (int chidx = 0; chidx < root->children.size(); chidx++)
    {
        cout<<root->children[chidx]->data;
        if (chidx != root->children.size() - 1)
        cout<<", ";
    }

    cout<<endl;

    for (int idx = 0; idx < root->children.size(); idx++)
    {
        printTree(root->children[idx]);
    }
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);
    printTree(root);
}