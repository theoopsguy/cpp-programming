#include <bits/stdc++.h>

using namespace std;

template <typename V>
class MapNode {
    public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key, V value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode() {
        delete next;
    }
};

template <typename V>
class ourmap {
    MapNode<V>** bucket;    //MapNode<V>* is the head of a linkedlist node & MapNode<V>** is the array of those heads.
    int count;
    int numBuckets;

    public:
    ourmap() {
        count = 0;
        numBuckets = 5;
        bucket = new MapNode<V>* [numBuckets];
        for (int i = 0; i < numBuckets; i++) {
            bucket[i] = NULL;   //to remove garbage addresses
        }
    }
    
    ~ourmap() {
        for(int i = 0; i < numBuckets; i++) {
            delete bucket[i];
        }
        delete []bucket;
    }

    int size() {
        return count;
    }

    V getValue(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = bucket[bucketIndex];
        while (head) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    double getLoadFactor() {
        return (1.0*count)/numBuckets;
    }

    private:
    int getBucketIndex(string key) {
        int hashCode = 0;   
        int currentCoeff = 1;
        
        for (int i = key.length() - 1; i >= 0; i--) {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets; //to prevent it from going out of range, we keep % it by numBuckets at every step
            currentCoeff *= 37; //take any prime no. as base coz prime nos. are proven to give better spread out results.
            currentCoeff = currentCoeff % numBuckets; //coz (n1*n2*n3)%r = ((n1%r)*(n2%r)*(n3%r))%r
        }

        return hashCode % numBuckets;
    }

    void rehash() {
        MapNode<V>** temp = bucket;
        bucket = new MapNode<V>* [2 * numBuckets];
        for (int i = 0; i < 2*numBuckets; i++) {
            bucket[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;
        //now it has become a completely new empty map.
        for (int i = 0; i < oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            while (head) {
                string key = head->key;
                V value = head->value;
                insert(key, value); //will insert in bucket array.
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            delete head;
        }
            delete [] temp;
    }

    public:
    void insert(string key, V value) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = bucket[bucketIndex];
        while (head != NULL) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = bucket[bucketIndex]; //if control has come to this point without returning from while loop means key does not exist.
        MapNode<V>* node = new MapNode<V>(key, value);
        node->next = head; //insert new node at the beginning of this linked list
        bucket[bucketIndex] = node;
        count++;

        //optimizing time complexity with rehashing
        double loadFactor = (1.0 * count)/numBuckets;   //1.0 done coz int/int will not give decimal results
        if (loadFactor > 0.7) {
            rehash();
        }
    }

    V remove(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = bucket[bucketIndex];
        MapNode<V>* prev = NULL;
        while (head != NULL) {
            if (head->key == key) {
                if (prev == NULL) { //if the key is found at the first node itself, bucket address needs to be replaced with the next node's address
                    bucket[bucketIndex] = head->next;
                }
                else {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;  //without this if we call delete, it will delete all nodes after it as well coz this destructor is written recursively.
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;   //if V would be ptr, 0 wud be NULL, for int also no problem, hence 0.
    }
};

int main() {
    ourmap<int> map;
    for (int i = 0; i < 10; i++) {
        char c = '0' + i;   //converting i to char
        string key = "abc";
        key += c;
        int value = 1 + i;
        map.insert(key, value);
        cout<<map.getLoadFactor()<<endl;    //to see if rehashing is working
    }

    cout<<map.size()<<endl;
    cout<<map.remove("abc2")<<endl;
    cout<<map.remove("abc7")<<endl;
    cout<<map.size()<<endl;

    for (int i = 0; i < 10; i++) {
        char c = '0' + i;
        string key = "abc";
        key += c;
        cout<<key<<": "<<map.getValue(key)<<endl;
    }

    cout<<map.size()<<endl;
    
    return 0;
}