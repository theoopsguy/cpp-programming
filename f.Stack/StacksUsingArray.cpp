#include <iostream>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int x)
    {
        if (nextIndex < capacity)
        {
            data[nextIndex] = x;
            nextIndex++;
        }
        else
        {
            cout<<"Stack is full"<<endl;
            return;
        }
    }

    int pop()
    {
        if (nextIndex == 0)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if (nextIndex == 0)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return data[nextIndex - 1];
    }
};

int main()
{
    StackUsingArray s(4);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;

    cout << boolalpha << s.isEmpty() << endl;

    return 0;
}