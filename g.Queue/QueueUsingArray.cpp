#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArray
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    QueueUsingArray(int s)
    {
        data = new int[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
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
        if (size == capacity)
        {
            cout<<"Queue is full."<<endl;
            return;
        }
        data[nextIndex] = x;
        nextIndex = (nextIndex + 1) % capacity;

        if (firstIndex == -1)
            firstIndex = 0;
        
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout<<"Queue is empty."<<endl;
            return -1;
        }

        return data[firstIndex];
    }

    T dequeu()
    {
        if (isEmpty())
        {
            cout<<"Queue is empty."<<endl;
            return -1;
        }

        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        return ans;
    }
};

int main()
{
    QueueUsingArray<int> q(5);

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