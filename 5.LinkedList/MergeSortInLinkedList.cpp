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

Node* FindMiddle (Node *head)
{
    Node *slow = head, *fast = head->next;

    while (fast && fast->next)
    {
        /*for even no. of nodes fast will point to null at the end of last iteration and 
        for odd no. of nodes, fast will point to last node at the end of last iteration.*/
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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
{
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

void mergeSort(Node **head)
{
    Node *curr = *head, *first, *second;

    if (curr == NULL || curr->next == NULL)
        return;

    Node *mid = FindMiddle(*head);

    first = *head; 
    second = mid->next;     //breaking the list into two halves
    mid->next = NULL;

    mergeSort(&first);      //calling recursion on two halves
    mergeSort(&second);

    *head = mergeRec(first, second);  //merging the 2 sorted halves
}

int main()
{
    Node *head = takeInput();
    mergeSort(&head);
    print(head);
    return 0;
}