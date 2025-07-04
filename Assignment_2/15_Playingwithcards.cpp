#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
vector<bool> isPrime(MAX, true);

void fun(vector<int>& primes) {
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i*i < MAX; i++) {
		if(isPrime[i]) {
			for(int j = i*i; j < MAX; j += i) {
				isPrime[j] = false;
			} 
		}
	}
	for(int i = 0; i < MAX; i++) {
		if(isPrime[i]) {
			primes.push_back(i);
		}
	}
}

int main() {
    vector<int> primes;
    fun(primes);
    int n, q;
    cin >> n >> q;

    stack<int> s;

    while (n--) {
        int d;
        cin >> d;
        s.push(d);
    }

    stack<int> a;
    stack<int> b;
    for (int i = 0; i < q; i++) {
        while (!s.empty()) {
            int x = s.top();
            int y = primes[i];
            if (x % y == 0) {
                b.push(x);
            } else {
                a.push(x);
            }
            s.pop();
        }
        while (!b.empty()) {
            int x = b.top();
            cout << x << endl;
            b.pop();
        }
        swap(s, a);
    }
	while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    
    return 0;
}