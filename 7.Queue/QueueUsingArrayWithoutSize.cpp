#include <iostream>
#include <vector>
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
    QueueUsingArray()
    {
        data = new T[5];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = 5;
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
            T* newData = new T[2*capacity];
            //creating a new array and copying elements in correct order
            int newIndex = 0;
            for (int idx = firstIndex; idx < capacity; idx++)
            {
                newData[newIndex] = data[idx];
                newIndex++;
            }

            for (int idx = 0; idx < firstIndex; idx++)
            {
                newData[newIndex] = data[idx];
                newIndex++;
            }

            delete []data;
            data = newData;
            firstIndex = 0;
            nextIndex = newIndex;
            capacity *= 2;
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
    QueueUsingArray<int> q;

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