#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> stk;

    for (char ch : s) {
    
        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        }
        
        else {
            if (stk.empty()) return false; 
            char top = stk.top();
            stk.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stk.empty();
}

int main() {
    string s;
    cin >> s;

    if (isValid(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
