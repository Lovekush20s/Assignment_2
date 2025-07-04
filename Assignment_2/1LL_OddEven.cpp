#include <iostream>  
using namespace std;  

class node {  
public:  
    int data;  
    node* next;  

    node(int val){  
        data = val;  
        next = NULL;  
    }  
};  
class Linklist {  
public:  
    node* head;  
    node* tail;  

    Linklist() {  
        head = NULL;  
        tail = NULL;  
    }  
    void input(int val) {  
        node* newnode = new node(val);  
        if (head == NULL) {  
            head = newnode;  
            tail = newnode;  
        } else {  
            tail->next = newnode;  
            tail = newnode;  
        }  
    }  

    void print() {  
        node* temp = head;  
        while (temp != NULL) {  
            cout << temp->data << " ";  
            temp = temp->next;  
        }  
        cout << endl;  
    }  

    void OddEven() {  
        if (head == NULL) return;  // Empty list  

        node* oddHead = NULL;  
        node* evenHead = NULL;  
        node* oddTail = NULL;  
        node* evenTail = NULL;  

        node* current = head;  

        while (current != NULL) {  
            if (current->data % 2 != 0) {  // Odd  
                if (oddHead == NULL) {  
                    oddHead = current;  
                    oddTail = current;  
                } else {  
                    oddTail->next = current;  
                    oddTail = current;  
                }  
            } else {  // Even  
                if (evenHead == NULL) {  
                    evenHead = current;  
                    evenTail = current;  
                } else {  
                    evenTail->next = current;  
                    evenTail = current; 
                }  
            }  
            current = current->next;  
        }  

        //odd ke last node even k head ko point karegi
        if (oddTail != NULL) {  
            oddTail->next = evenHead;  
        }  

        // even ki last node NULL hogi  
        if (evenTail != NULL) {  
            evenTail->next = NULL;  
        }  

        if (oddHead == NULL){
			head = evenHead;
		} else{
			head = oddHead;
		}
		
        if (evenTail != NULL) {  
            tail = evenTail;  
        } else {  
            tail = oddTail; // ager koi even no nahi ho to tail ko oddno p set kar do
        }  
    }  
};  

int main() {  
    Linklist list;  
    int n;  
    cin >> n;  
    while (n--) {  
        int x;  
        cin >> x;  
        list.input(x);  
    }  

    list.OddEven();  
    list.print();  

    return 0;  
}