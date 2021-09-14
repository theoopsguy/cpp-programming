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
    return 0;
}