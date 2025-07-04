#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;  

    while (T--) {
        int N;
        cin >> N;

        int count = 0;
        bool isValid = true;

        for (int i = 0; i < N; ++i) {
            int op;
            cin >> op;

            if (op == 1) {
                count++;  
            } else if (op == 0) {
                count--; 
                if (count < 0) {
                    isValid = false;
                }
            }
        }
        if (isValid)
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }
    return 0;
}
