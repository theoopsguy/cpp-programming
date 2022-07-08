#include <iostream>
#include <vector>
using namespace std;

class StackUsingArray
{
    vector<int> data;
    int nextIndex;

    public:
    StackUsingArray()
    {
        nextIndex = 0;
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
        data.push_back(x);
        nextIndex++;
    }

    int pop()
    {
        if (nextIndex == 0)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        nextIndex--;
        int item = data[nextIndex];
        data.pop_back();
        return item;
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
    StackUsingArray s;

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