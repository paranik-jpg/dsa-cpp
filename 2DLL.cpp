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

void printDLL(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* arrToDLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }

    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node* deleteKth(Node* head, int k){
    if(head == NULL) return NULL;
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL) return NULL;
    else if(prev == NULL) return(deleteHead(head));
    else if(front == NULL) return(deleteTail(head));

    prev->next = front;
    front->back = prev;
    temp->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

void deleteNode(Node* temp){
    Node* front = temp->next;
    Node* prev = temp->back;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;
    temp->back = nullptr;
    temp->next = nullptr;
    free(temp);
    return;
}

Node* insertBefHead(Node* head, int val){
    Node* newNode = new Node(val,head,nullptr);
    head->back = newNode;
    return newNode;
}

Node* insertBefTail(Node* head, int val){
    if(head == NULL) return new Node(val, nullptr, nullptr);
    if(head->next == NULL) return new Node(val, head, nullptr);

    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

Node* insertBefKth(Node* head, int val, int k){
    if(k==1) return insertBefHead(head,val);

    Node* temp = head;
    int cnt = 0;
    while(temp->next != NULL){
        cnt++;
        if(cnt==k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

void insertBefNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val,node,prev);
    prev->next = newNode;
    node->back = newNode;
}

Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* last = NULL;
    Node* curr = head;

    while(curr!=NULL){
        last = curr->back;
        curr->back = curr->next;
        curr->next = last;
        curr = curr->back;
    }

    head = last->back;
}

int main() {
    vector<int> roll = {11, 0, 4, 5};

    Node* head = arrToDLL(roll);

    head = reverseDLL(head);

    printDLL(head);

    return 0;
}