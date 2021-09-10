#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *first, *last;
    LinkedList()
    {
        first = NULL;
        last = NULL;
    }
    LinkedList(int arr[], int n);
    ~LinkedList();
    void Display();
    void Insert (int idx, int x);
    void InsertLast (int x);
    int Delete (int idx);
    int Length();
    void makeLoop();
    bool isLoop();
};

LinkedList :: LinkedList(int arr[], int n)
{
    Node *temp;
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int idx = 1; idx < n; idx++)
    {
        temp = new Node;
        temp->data = arr[idx];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

LinkedList :: ~LinkedList()
{
    Node *temp = first;

    while (first)
    {
        first = first->next;
        delete temp;
        temp = first;
    }

    last = first;
}

void LinkedList::Display()
{
    Node *temp = first;

    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void LinkedList::Insert (int idx, int x)
{
    Node *temp = first, *n;

    if (idx < 0 || idx > Length())
        return;

    n = new Node;
    n->data = x;
    n->next = NULL;

    if (idx == 0)
    {
        n->next = first;
        first = n;
    }
    else
    {
        for (int pos = 0; pos < idx-1; pos++)
            temp = temp->next;

        if (temp->next == NULL)
            last = n;

        n->next = temp->next;
        temp->next = n;
    }
}

void LinkedList::InsertLast (int x)
{
    Node *n = new Node;
    n->data = x;

    if (first == NULL)
    {
        first = n;
        last = n;
    }

    else
    {
        last->next = n;
        last = n;
    }
}

int LinkedList::Delete (int idx)
{
    Node *temp = first;
    int x;

    if (idx < 0 || idx > Length())
        return -1;

    if(idx == 0)
    {
        temp = first;
        first = first->next;
        x = temp->data;
        delete temp;
    }

    else
    {
        for (int pos = 0; pos < idx - 1; pos++)
            temp = temp->next;
        //if idx 2 is to be deleted, after loop ends temp will point to 1.
        Node *del = temp->next; //del points to 2 (to be deleted)
        Node *n = del->next;    //n points to ele after 2 i.e. 3 (to be linked with 1 after deletion)
        x = del->data;
        
        if (del->next == NULL)
            last = temp;    //if the node to be deleted is the last node

        delete del;
        temp->next = n;
    }

    return x;
}

int LinkedList::Length ()
{
    int l = 0;
    Node *temp = first;

    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }

    return l;
}

void LinkedList::makeLoop()
{
    Node *temp = first;
    for (int cnt = 0; cnt < 4; cnt++)
    {
        temp = temp->next;
    }
    last->next = temp;
}

bool LinkedList::isLoop()
{
    Node *p = first, *q = first;

    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL? q->next : NULL;
    } while (p != NULL && q != NULL && p != q);
    
    if (p == q)
        return true;
    else
        return false;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    LinkedList lc(arr, 8), lnc(arr, 8); 
    lc.makeLoop();
    cout<<boolalpha<<lc.isLoop()<<endl<<lnc.isLoop(); 
    return 0;
}