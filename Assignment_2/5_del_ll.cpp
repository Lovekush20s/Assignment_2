#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Insert node at tail
void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

// Delete nodes with lesser value than max on right
Node* deleteLesserNodes(Node* head) {
    head = reverseList(head);

    Node* curr = head;
    int maxVal = curr->data;
    Node* prev = curr;
    curr = curr->next;

    while (curr) {
        if (curr->data < maxVal) {
            prev->next = curr->next; // Delete current node
            delete curr;
            curr = prev->next;
        } else {
            maxVal = curr->data;
            prev = curr;
            curr = curr->next;
        }
    }

    return reverseList(head);
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, val;
    cin >> n;

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtTail(head, val);
    }

    head = deleteLesserNodes(head);
    printList(head);

    return 0;
}
