#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node *next;

    Node (int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print (Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node *takeInput()
{
    int data;
    cin>>data;
    Node *head = NULL, *tail = head;
    while (data != -1)
    {
        Node *newNode = new Node (data);
        
        if (head == NULL)
        {
            head = newNode;
            tail = head;
        }

        else 
        {
            tail->next = newNode; 
            tail = newNode;
        }

        cin >> data;
    }
    return head;
}

int length(Node *head)
{
    int l = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

void Insert(Node *head, int idx, int x)
{
    Node *ptr = head;
    
    if (idx < 0 || idx > length(head))
        return;

    Node *newNode = new Node (x);

    if (idx == 0)
    {
        newNode->next = head;
        head = newNode;
    }

    for (int pos = 0; pos < idx - 1 && ptr != NULL; pos++)
    {
        ptr = ptr->next;
    }

    if (ptr)
    {
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

int main()
{
    Node *head = takeInput();
    int idx, data;
    cin>>idx>>data;
    Insert (head, idx, data);
    print(head);

    return 0;
}