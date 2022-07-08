#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;

    Node(int data)
    {
        this->data = data;
    }

    ~Node()
    {
        int size = children.size();
        for (int index = 0; index < size; index++)
        {
            delete children[index];
        }
    }
};

Node *takeInput()
{
    int size;

    cin >> size;

    int *input = new int[size];

    for (int index = 0; index < size; index++)
    {
        cin >> input[index];
    }

    Node *root = NULL;

    stack<Node *> nodes;

    for (int index = 0; index < size; index++)
    {
        if (input[index] == -1)
        {
            nodes.pop();
        }

        else
        {
            Node *newNode = new Node(input[index]);

            if (nodes.size() == 0)
            {
                root = newNode;
            }

            else
            {
                nodes.top()->children.push_back(newNode);
            }

            nodes.push(newNode);
        }
    }

    return root;
}

Node* maxNode(Node *root)
{
    Node *max = root;
    
    for (int idx = 0; idx < root->children.size(); idx++)
    {
        if (root->children[idx]->data > max->data)
            max = root->children[idx];
            
        Node* tempMax = maxNode(root->children[idx]);
        
        max = tempMax->data > max->data ? tempMax : max;
    }
    
    return max;
}

int main()
{
    Node *root = takeInput();
    Node *max = maxNode(root);
    cout<<max->data;
    return 0;
}