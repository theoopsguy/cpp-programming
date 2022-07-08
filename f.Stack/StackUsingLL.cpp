#include <iostream>
using namespace std;

template <typename T>
class Node 
{
public:
    T data;
    Node<T> *next;

    Node (T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class StackUsingLL
{
    Node<T> *head;
    int length;
    
    public:
    StackUsingLL()
    {
        head = NULL;
        length = 0; 
    }

    int size()
    {
        return length;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    void push(T x)
    {
        Node<T> *temp = new Node<T>(x);
        temp->next = head;
        head = temp;
        length++;
    }

    T pop()
    {
        if (head == NULL)
        {
            cout<<"Stack is empty.";
            return -1;
        }
        Node<T> *temp = head;
        head = head->next;
        T item = temp->data;
        delete temp;
        length--;
        return item;
    }

    T top()
    {
        if (head == NULL)
        {
            cout<<"Stack is empty.";
            return -1;
        }
        return head->data;
    }
};

int main()
{
    StackUsingLL<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;

    cout << boolalpha << s.isEmpty() << endl;

    return 0;
}