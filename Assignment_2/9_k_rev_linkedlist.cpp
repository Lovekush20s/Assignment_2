#include <iostream>
using namespace std;

// Linked List Node
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to insert at end
void insertAtTail(Node*& head, int val) {
    if (head == NULL) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new Node(val);
}

// Function to reverse k nodes in the linked list
Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    int count = 0;
    // Count k nodes
    while (curr != NULL && count < k) {
        curr = curr->next;
        count++;
    }
    if (count < k) return head; 

    Node* prev = NULL;
    curr = head;
    Node* next = NULL;
    count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
        head->next = reverseKGroup(next, k);

    return prev; 
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    Node* head = NULL;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        insertAtTail(head, val);
    }

    head = reverseKGroup(head, K);
    printList(head);

    return 0;
}
