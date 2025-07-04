#include <iostream>
#include <unordered_set>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to insert node at tail
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

// Function to find and print the first matching triplet
void findTriplet(Node* a, Node* b, Node* c, int target) {
    for (Node* ptr1 = a; ptr1 != NULL; ptr1 = ptr1->next) {
        for (Node* ptr2 = b; ptr2 != NULL; ptr2 = ptr2->next) {
            int required = target - (ptr1->data + ptr2->data);

            // Now search for 'required' in list c
            for (Node* ptr3 = c; ptr3 != NULL; ptr3 = ptr3->next) {
                if (ptr3->data == required) {
                    cout << ptr1->data << " " << ptr2->data << " " << ptr3->data << endl;
                    return; // Found the first valid triplet
                }
            }
        }
    }

    // If no such triplet found
    cout << "No Triplet Found" << endl;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    Node *a = NULL, *b = NULL, *c = NULL;
    int val;

    // Read list a
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtTail(a, val);
    }

    // Read list b
    for (int i = 0; i < m; i++) {
        cin >> val;
        insertAtTail(b, val);
    }

    // Read list c
    for (int i = 0; i < k; i++) {
        cin >> val;
        insertAtTail(c, val);
    }

    // Read target
    int target;
    cin >> target;

    // Find triplet
    findTriplet(a, b, c, target);

    return 0;
}
