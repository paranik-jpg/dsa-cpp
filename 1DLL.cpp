#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* arrToLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        cnt ++;
    }
    return cnt;
}

bool isThere(Node* head, int ele){
    Node* temp = head;
    while(temp){
        if(temp->data == ele){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* removeElement(Node* head, int ele){
    if(head == NULL) return head;
    if (head->data == ele){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head; 
    Node* prev = nullptr;
    while(temp!=NULL){
        if(temp->data == ele){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* removeKthElement(Node* head, int k){
    if(head == NULL) return head;
    if (k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head; 
    Node* prev = nullptr;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = nullptr;
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* insertAtHead(Node* head, int headval){
    return new Node(headval, head);
}

Node* insertAtTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node* naya = new Node(val);
    temp->next = naya;
    return head;
}

Node* insertAtK(Node* head, int val, int k){
    if(head == NULL){
        if(k==1) return new Node(val);
        else return NULL;
    }

    if(k==1) return new Node(val, head);
    int cnt = 0; Node* temp = head; 
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break; 
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBef(Node* head, int inval, int val){
    if(head == NULL) return NULL;

    if(head->data == val) return new Node(inval, head);
    Node* temp = head; 
    while(temp->next!=NULL){
        if(temp->next->data == val){
            Node* newNode = new Node(inval);
            newNode->next = temp->next;
            temp->next = newNode;
            break; 
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> roll = {11, 0, 4, 5};

    Node* head = arrToLL(roll);

    cout << endl;

    printLL(insertBef(head,100,4));

    return 0;
}