#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}

Node* partitionList(Node* head, int x) {
    Node* beforeHead = new Node(0);  
    Node* afterHead = new Node(0);   

    Node* before = beforeHead;
    Node* after = afterHead;

    while (head != NULL) {
        if (head->data < x) {
            before->next = head;
            before = before->next;
        } else {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }

    after->next = NULL;          
    before->next = afterHead->next; 

    return beforeHead->next;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int N, X;
    cin >> N >> X;

    Node* head = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        insertAtTail(head, val);
    }

    head = partitionList(head, X);
    printList(head);

    return 0;
}
