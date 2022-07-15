#include <iostream>
#include <queue>
using namespace std;

template <typename T>
    class BinaryTreeNode{
        public:
        T data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode(){
            delete left;
            delete right; 
        }
    };

BinaryTreeNode<int>* takeInputLevelWise(){
    
    int rootData;
    cout<<"Enter root data \n";
    cin>>rootData;

    if (rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;

        if (leftChildData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        
        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;

        if (rightChildData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root;

}

void printTree(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }

    cout<<root->data<<": ";
    
    if (root->left){
        cout<<"L"<<root->left->data<<" ";
    }

    if (root->right){
        cout<<"R"<<root->right->data<<" ";
    }

    cout<<endl;

    printTree(root->left);
    printTree(root->right);

}

int countNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inOrder(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();

    inOrder(root);

    delete root;

    return 0;
}