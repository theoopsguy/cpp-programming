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
            head->next = head;
            tail = head;
        }

        else 
        {
            newNode->next = tail->next;
            tail->next = newNode; 
            tail = newNode;
        }

        cin >> data;
    }
    return head;
}

int length(Node *head)
{
    int l = 1;
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

void Insert (Node** head, int idx, int x)
{
    Node* p = *head;
    Node* t = new Node(x);

    if (idx < 0 || idx > length(*head))
        return;

    if (idx == 0)
    {
        if (*head == NULL)
        {
            *head = t;
            t->next = *head;
        }
        else
        {
            while (p->next != *head)
                p = p->next;

            t->next = *head;
            p->next = t;
            *head = t;
        }
    }

    else
    {
        for (int pos = 0; pos < idx - 1; pos++)
        {
            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}

int Delete(Node **head, int index)
{
    Node *p = *head, *q;
    int x;

    if(index < 0 || index >= length(*head))
        return -1;
    
    if(index==0)
    {
        while(p->next!=*head)    //traversing to last node
            p=p->next;
    
        Node *h = *head;
        x = h->data;

        if(*head==p)
        {
            delete *head;
            *head=NULL;
        }

        else
        {
            Node *h = *head;
            p->next=h->next;
            delete *head;
            *head=p->next;
        }
    }

    else
    {
        for(int pos=0; pos<index-1; pos++)
            p=p->next;

        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}

void print (Node* head)
{
    Node *h = head;
    do
    {
        cout<<h->data<<" ";
        h=h->next;

    } while (h != head);

    cout<<endl;
}

void printRec (Node *head, Node *temp)
{
    static int flag = 0;

    if (temp != head || flag == 0)
    {
        flag = 1;
        cout << temp->data << " ";
        printRec(head, temp->next);
    }

    flag = 0;   //so that this fn can be used again as flag is static.
}

int main()
{
    Node *chead = takeInput();
    printRec(chead, chead);
    cout<<endl;
    int idx, data;
    cin>>idx;
    //cin>>data;
    //Insert(&chead, idx, data);
    cout << Delete(&chead, idx)<<endl;
    print(chead);
    return 0;
}