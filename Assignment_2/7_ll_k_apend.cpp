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

// Find length of list
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Append last K nodes to front
Node* appendLastKToFront(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int len = getLength(head);
    k = k % len;  // Handle k > len
    if (k == 0) return head;

    int stepsToNewHead = len - k;

    Node* temp = head;
    Node* prev = NULL;

    // Traverse to (len-k)th node
    for (int i = 0; i < stepsToNewHead; i++) {
        prev = temp;
        temp = temp->next;
    }

    Node* newHead = temp;
    prev->next = NULL;

    // Go to end of new list and attach old head
    Node* tail = newHead;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = head;

    return newHead;
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
    int n, k, val;
    cin >> n;

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtTail(head, val);
    }

    cin >> k;

    head = appendLastKToFront(head, k);
    printList(head);
    return 0;
}
