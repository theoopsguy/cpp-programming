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

Node* Insert(Node *head, int idx, int x)
{
    Node *ptr = head;
    
    if (idx < 0 || idx > length(head))
        return head;

    Node *newNode = new Node (x);

    if (idx == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
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

    return head;
}

Node *InsertRec(Node *head, int idx, int data)
{
    if (head == NULL || idx < 0)
        return head;

    if (idx == 1)
    { //idx == 1 coz we need to stop and do our work at the node before the idx where elements is to be inserted
        Node *newNode = new Node(data);
        newNode->next = head->next;
        head->next = newNode;
        return head;
    }

    if (idx == 0)
    {//first element is to be added
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *temp = InsertRec(head->next, idx - 1, data);
    return head;
}

Node* deleteNode (Node *head, int idx)
{
    Node *temp = head;

    if (idx < 0 || idx > length(head) || head == NULL)
        return head;

    if (idx == 0)
    {
        head = head->next;
        delete temp;
    }

    else 
    {
        for (int pos = 0; pos < idx - 1; pos++)
            temp = temp->next;

        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }

    return head;
}

Node* DeleteRec (Node *head, int idx)
{
    if (head == NULL || idx < 0)
        return head;

    if (idx == 1)
    {
        Node *del = head->next;
        head->next = del->next;
        delete del;
        return head;
    }    

    if (idx == 0)
    {
        Node *del = head;
        head = head->next;
        delete del;
        return head;
    }

    Node *temp = DeleteRec(head->next, idx - 1);
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

    *head = merge (first, second);  //merging the 2 sorted halves
}

int main()
{
    Node *head = takeInput();
    mergeSort(&head);
    print(head);
    return 0;
}