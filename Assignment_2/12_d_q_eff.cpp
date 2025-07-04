#include <iostream>
#include <stack>
using namespace std;

class DequeueEfficientQueue {
private:
    stack<int> s1, s2;

public:
    
    void enqueue(int x) {
    
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        
        s1.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int front = s1.top();
        s1.pop();
        return front;
    }

    // Check if queue is empty
    bool isEmpty() {
        return s1.empty();
    }
};

int main() {
    int n;
    cin >> n;

    DequeueEfficientQueue q;

    // Enqueue 0 to n-1
    for (int i = 0; i < n; i++) {
        q.enqueue(i);
    }

    // Dequeue and print
    while (!q.isEmpty()) {
        cout << q.dequeue();
        if (!q.isEmpty()) cout << " ";
    }

    cout << endl;
    return 0;
}
