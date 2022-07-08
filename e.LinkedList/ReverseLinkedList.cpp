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

Node *ReverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *smallAns = ReverseLL(head->next); //asking recursion to reverse and give rest of the list
    Node *temp = smallAns;

    while (temp->next)
    {
        temp = temp->next;  //O(n^2) complexity coz we have to travesrse to find tail each time
    }
    
    temp->next = head;
    head->next = NULL;
    return smallAns;
}   

Node *ReverseLL_2(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *smallAns = ReverseLL_2(head->next); //asking recursion to reverse and give rest of the list

    Node *tail = head->next;    //coz my curr head is still connected to the last element of the reversed list    
    tail->next = head;
    head->next = NULL;
    return smallAns;
}   //Best solution

class Pair 
{
    public:
    Node *head, *tail;
};

Pair ReverseLLFast(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = ReverseLLFast(head->next); //asking recursion to reverse and give rest of the list
    
    smallAns.tail->next = head;     //O(n) complexity
    smallAns.tail = head;
    head->next = NULL;
    return smallAns;
}

Node *ReverseLL_It(Node *head)  //Iterative
{
    Node *temp = head, *prev = NULL;

    while (temp)
    {
        Node *cur = temp;
        temp = temp->next;
        cur->next = prev;
        prev = cur;
    }

    return prev;
}

int main()
{
    Node *head1 = takeInput();
    Pair reverse = ReverseLLFast(head1);
    print(reverse.head);

    cout<<endl;

    Node *head2 = takeInput();
    head2 = ReverseLL_2(head2);     //Best solution
    print (head2);

    cout<<endl;

    Node *head3 = takeInput();
    head3 = ReverseLL_It(head3);
    print(head3);
    
    return 0;
}