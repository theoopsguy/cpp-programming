#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
    T data;
    Node *next;

    Node(T x)
    {
        this->data = x;
        this->next = NULL;
    }
};

template <typename T>
class QueueUsingLL
{
    Node<T> *head, *tail;
    int size;

    public:
    QueueUsingLL()
    {
        head = tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T x)
    {
        if (head == NULL)
        {
            head = new Node<T>(x);
            tail = head;
        }
        else
        {
            Node<T> *temp = new Node<T>(x);
            tail->next = temp;
            tail = temp;
        }

        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout<<"Queue is empty."<<endl;
            return -1;
        }

        return head->data;
    }

    T dequeu()
    {
        if (isEmpty())
        {
            cout<<"Queue is empty."<<endl;
            return -1;
        }

        T ans = head->data;
        Node<T> *del = head;
        head = head->next;
        delete del;
        size--;
        return ans;
    }
};

int main()
{
    QueueUsingLL<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.front()<<endl;
    cout<<q.dequeu()<<endl;
    cout<<q.dequeu()<<endl;
    cout<<q.dequeu()<<endl;

    cout<<q.getSize()<<endl;
    cout<<boolalpha<<q.isEmpty()<<endl;

    return 0;
}