#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to insert at tail
void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Function to get length of list
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Recursive function to add lists
Node* addListsHelper(Node* l1, Node* l2, int &carry) {
    if (!l1 && !l2) return NULL;

    Node* nextNode = addListsHelper(
        l1 ? l1->next : NULL,
        l2 ? l2->next : NULL,
        carry
    );

    int sum = carry;
    if (l1) sum += l1->data;
    if (l2) sum += l2->data;

    carry = sum / 10;
    Node* current = new Node(sum % 10);
    current->next = nextNode;

    return current;
}

// Padding helper to align lists
Node* padList(Node* head, int diff) {
    while (diff--) {
        Node* newNode = new Node(0);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Function to add two lists
Node* addTwoLists(Node* l1, Node* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    // Pad the shorter list
    if (len1 < len2) l1 = padList(l1, len2 - len1);
    else l2 = padList(l2, len1 - len2);

    int carry = 0;
    Node* result = addListsHelper(l1, l2, carry);

    // If carry remains
    if (carry) {
        Node* newHead = new Node(carry);
        newHead->next = result;
        result = newHead;
    }

    return result;
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, m, val;
    cin >> n >> m;

    Node* l1 = NULL;
    Node* l2 = NULL;

    // Read list 1
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtTail(l1, val);
    }

    // Read list 2
    for (int i = 0; i < m; i++) {
        cin >> val;
        insertAtTail(l2, val);
    }

    Node* result = addTwoLists(l1, l2);
    printList(result);

    return 0;
}
