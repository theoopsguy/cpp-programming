#include <iostream>
#include <queue>
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

void printTreeLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
        return;     
    /*would work fine even without this base case, this is just to handle the edge case when NULL is passed to the function.*/ 

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        cout << pendingNodes.front()->data << ": ";

        for (int chidx = 0; chidx < pendingNodes.front()->children.size(); chidx++)
        {
            cout<<pendingNodes.front()->children[chidx]->data;

            if (chidx != root->children.size() - 1)
                cout<<", ";
                
            pendingNodes.push(pendingNodes.front()->children[chidx]);
        }

        cout<<endl;
        pendingNodes.pop();
    }
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout<<"Enter root data: "<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int> (rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter no. of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;

        for (int idx = 0; idx < numChild; idx++)
        {
            cout<<"Enter "<<idx<<"th child of "<<front->data<<endl;
            int childData;
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    printTreeLevelWise(root);

    return 0;
}
/*
Sample Input:
Enter root data:
1
Enter no. of children of 1
3
Enter 0th child of 1
2
Enter 1th child of 1
3
Enter 2th child of 1
4
Enter no. of children of 2
2
Enter 0th child of 2
5
Enter 1th child of 2
6
Enter no. of children of 3
0
Enter no. of children of 4
0
Enter no. of children of 5
0
Enter no. of children of 6
0

Corresponding Output:
1: 2, 3, 4
2: 5, 6,
3:
4:
5:
6:
*/