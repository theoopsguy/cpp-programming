#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
    vector<int> pq;

    public:
    PriorityQueue() {

    }

    bool isEmpty() {
        return pq.size() == 0;
    }

    int getSize() {
        return pq.size();
    }

    int getMin() {
        if (isEmpty()) {
            return -1;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;
        int parentIndex = (childIndex - 1) / 2;

        while (childIndex != 0 && pq[childIndex] < pq[parentIndex]) {
            int temp = pq[childIndex];
            pq[childIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
            //cn vid diff method so test        
        }
    }

    int removeMin() {
        if (isEmpty()) {
            return -1;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        int childIndex1 = 2 * parentIndex + 1;
        int childIndex2 = 2 * parentIndex + 2;

        while (childIndex1 < pq.size() && (pq[parentIndex] > pq[childIndex1] || pq[parentIndex] > pq[childIndex2])) {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[childIndex1]) {
                minIndex = childIndex1;
            }
            if (childIndex2 < pq.size() && pq[minIndex] > pq[childIndex2]) {
                minIndex = childIndex2; 
            }
            //the childindex with minimum value will make it to minIndex.
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            childIndex1 = 2 * parentIndex + 1;
            childIndex2 = 2 * parentIndex + 2;
        }

        return ans;
    }
};

int main() {
    PriorityQueue p;

    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<p.getSize()<<endl;
    cout<<p.getMin()<<endl;

    while(!p.isEmpty()) {
        cout<<p.removeMin()<<" ";
    }
    cout<<endl;

    return 0;
}