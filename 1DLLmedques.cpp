#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int num;
    node* next;
    node(int val) {
        num = val;
        next = NULL;
    }
};

// Utility function to insert node at the end of the linked list
void insertNode(node* &head, int val) {
    node* newNode = new node(val);
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

// Utility function to check presence of intersection
node* intersectionPresent(node* head1, node* head2) {
    int n1 =0, n2 = 0;
    node* t1 = head1;
    node* t2 = head2;

    while(t1!=NULL){
        n1++;
        t1 = t1->next;
    }

    while(t2!=NULL){
        n2++;
        t2 = t2->next;
    }

    t1 = head1;
    t2 = head2;

    int diff = abs(n1-n2);
    if(n1>n2){
        while(diff){
            diff--;
            t1 = t1->next;
        }
    }else {
        while(diff){
            diff--;
            t2 = t2->next;
        }
    }

    while(t1!=t2){
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1;
}

// Utility function to print linked list
void printList(node* head) {
    while (head->next != NULL) {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
}

int main() {
    // Creation of both lists
    node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    node* head1 = head;
    head = head->next->next->next;  // Intersection point
    node* headSec = NULL;
    insertNode(headSec, 3);
    node* head2 = headSec;
    headSec->next = head;  // Creating intersection
    
    // Printing of the lists
    cout << "List1: ";
    printList(head1);
    cout << "List2: ";
    printList(head2);
    
    // Checking if intersection is present
    node* answerNode = intersectionPresent(head1, head2);
    if (answerNode == NULL) 
        cout << "No intersection\n";
    else 
        cout << "The intersection point is " << answerNode->num << endl;
    
    return 0;
}
