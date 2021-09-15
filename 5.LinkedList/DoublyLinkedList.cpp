#include <iostream>
using namespace std;

class Node 
{
public:
    Node *prev;
    int data;
    Node *next;

    Node (int data)
    {
        this->data = data;
        next = NULL;
    }
};

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
            head->next = NULL;
            head->prev = NULL;
            tail = head;
        }

        else 
        {
            newNode->next = NULL;
            tail->next = newNode; 
            newNode->prev = tail;
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

void print (Node* head)
{
    Node *h = head;

    while (h)
    {
        cout<<h->data<<" ";
        h = h->next;
    }

    cout<<endl;
}

Node* Insert(Node *head, int idx, int x)
{
    Node *ptr = head;
    
    if (idx < 0 || idx > length(head))
        return head;

    Node *newNode = new Node (x);

    if (idx == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        head->prev = NULL;
        return head;
    }

    for (int pos = 0; pos < idx - 1 && ptr != NULL; pos++)
    {
        ptr = ptr->next;
    }

    if (ptr)
    {
        newNode->next = ptr->next;
        newNode->prev = ptr;
        if (newNode->next) 
            newNode->next->prev = newNode;
        ptr->next = newNode;
    }

    return head;
}

Node* deleteNode (Node *head, int idx)
{
    Node *temp = head;

    if (idx < 0 || idx >= length(head) || head == NULL)
        return head;

    if (idx == 0)
    {
        head = head->next;
        if (head)
            head->prev = NULL;
        delete temp;
    }

    else 
    {
        for (int pos = 0; pos < idx - 1; pos++)
            temp = temp->next;

        Node *del = temp->next;
        temp->next = del->next;

        if (temp->next)
            temp->next->prev = temp;

        delete del;
    }

    return head;
} 

Node *Reverse(Node *head)
{
    Node *p = head;

    while(p)
    {
        Node *temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        if (p->prev == NULL)
            head = p;

        p = p->prev;
    } 

    return head;
}

int main()
{
    Node *dhead = takeInput();
    int idx, data;
    cin>>idx>>data;
    dhead = Insert(dhead, idx, data);
    int didx;
    cin>>didx;
    dhead = deleteNode(dhead, didx);
    print(dhead);  
    return 0;
}