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

TreeNode<int> *takeInput()
{
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;
    TreeNode<int> *root = new TreeNode<int> (data);

    int n;
    cout<<"Enter no. of children of "<<root->data<<endl;
    cin>>n;

    for (int idx = 0; idx < n; idx++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInput();

    printTree(root);

    return 0;
}

/*
Sample Input:

Enter data:
1
Enter no. of children of 1
3
Enter data:
2
Enter no. of children of 2
2
Enter data:
3
Enter no. of children of 3
0
Enter data:
4
Enter no. of children of 4
0
Enter data:
5
Enter no. of children of 5
1
Enter data:
6
Enter no. of children of 6
0
Enter data:
7
Enter no. of children of 7
0

Output:
1: 2, 5, 7
2: 3, 4
3:
4:
5: 6
6:
7:
*/