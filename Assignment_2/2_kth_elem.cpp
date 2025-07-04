#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to insert node at end
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

// Function to find kth node from end
int findKthFromEnd(Node* head, int k) {
    Node* fast = head;
    Node* slow = head;

    // Move fast k steps ahead
    for (int i = 0; i < k; i++) {
        if (!fast) return -1; // If k > length
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}

int main() {
    Node* head = NULL;
    int val;

    // Read input until -1
    while (cin >> val && val != -1) {
        insertAtTail(head, val);
    }

    int k;
    cin >> k;

    int result = findKthFromEnd(head, k);
    if (result == -1)
        cout << "Invalid Input" << endl;
    else
        cout << result << endl;

    return 0;
}
