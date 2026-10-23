#include <bits/stdc++.h>
using namespace std;

// Class representing the LRU Cache
class LRUCache {
public:
    class Node{
        public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int akey, int avalue){
            key = akey;
            value = avalue;
        }
    };    

    int cap;
    map<int, Node*> mpp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    // Constructor to initialize LRU cache
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node){
        Node* agla = node->next;
        Node* pichchla = node->prev;
        pichchla->next = agla;
        agla->prev = pichchla;
    }

    void addNodeAfterHead(Node* node){
        Node* agla = head->next;
        head->next = node;
        node->next = agla;
        node->prev = head;
        agla->prev = node;
    }

    // Function to get value from cache
    int get(int key_) {
        if(mpp.find(key_) == mpp.end()) return -1;
        Node* node = mpp[key_];
        deleteNode(node);
        addNodeAfterHead(node);
        return node->value;
    }

    // Function to put key-value into cache
    void put(int key_, int value) {
        if(mpp.find(key_) != mpp.end()){
            Node* node = mpp[key_];
            node->value = value;
            deleteNode(node);
            addNodeAfterHead(node);
        } else {
            if(mpp.size() == cap){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node* newNode = new Node(key_, value);
            mpp[key_] = newNode;
            addNodeAfterHead(newNode);
        }
    }
};

// Driver code
int main() {
    // Create cache with capacity 2
    LRUCache cache(2);

    // Put values in cache
    cache.put(1, 1);
    cache.put(2, 2);

    // Get value for key 1
    cout << cache.get(1) << endl; 

    // Insert another key (evicts key 2)
    cache.put(3, 3);

    // Key 2 should be evicted
    cout << cache.get(2) << endl; 

    // Insert another key (evicts key 1)
    cache.put(4, 4);

    // Key 1 should be evicted
    cout << cache.get(1) << endl; 

    // Key 3 should be present
    cout << cache.get(3) << endl; 

    // Key 4 should be present
    cout << cache.get(4) << endl; 

    return 0;
}
