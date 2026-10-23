#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1,Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

vector<pair<int,int>> findPairs(Node* head, int k){
    vector<pair<int,int>> vec;
    Node* left = head;

    Node* right = head;
    while(right->next!=NULL) right = right->next;

    while(leftt->data<right->data){
        if(left->data+right->data == k) {
            vec.push_back({left->data,right->data});
            right = right->back;
            left = left->next;
        }
        else if(left->data+right->data > k) right = right->back;
        else left = left->next;
    }
    
    return vec;
}

int main() {
    vector<int> roll = {11, 0, 4, 5};

    Node* head = arrToDLL(roll);

    head = reverseDLL(head);

    printDLL(head);

    return 0;
}