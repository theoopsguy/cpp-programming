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

Node *merge (Node *head1, Node *head2)
{   
    Node *fhead = NULL, *ftail = fhead;

    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            if (fhead == NULL)
            {
                fhead = ftail = head1;
                head1 = head1->next;
            }
            else
            {
                ftail->next = head1;
                ftail = ftail->next;
                head1 = head1->next;
            }
        }

        else if (head1->data > head2->data)
        {
            if (fhead == NULL)
            {
                fhead = ftail = head2;
                head2 = head2->next;
            }
            else
            {
                ftail->next = head2;
                ftail = ftail->next;
                head2 = head2->next;
            }
        }
    }

    while (head1)
    {
        ftail->next = head1;
        head1 = head1->next;
        ftail = ftail->next;
    }

    while (head2)
    {
        ftail->next = head2;
        head2 = head2->next;
        ftail = ftail->next;
    }

    return fhead;
}

Node *mergeRec(Node *head1, Node *head2)
{   //Recursive and faster way to merge 2 sorted lists
    Node *fhead = NULL;
    
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
    
    if (head1->data <= head2->data)
    {
        fhead = head1;
        fhead->next = mergeRec(head1->next, head2);
    }
    else
    {
        fhead = head2;
        fhead->next = mergeRec(head1, head2->next);
    }
    return fhead;
}

int main()
{
    Node *head1 = takeInput();
    Node *head2 = takeInput();
    Node *headMerged = mergeRec(head1, head2);
    print(headMerged);
    return 0;
}