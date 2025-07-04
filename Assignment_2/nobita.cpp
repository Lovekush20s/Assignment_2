#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--) {
        int candy, n;
        cin >> candy >> n;
        int rem = candy%n;
        int take = n-rem;

        cout << min(rem, take) << endl;
    }
    return 0;
}