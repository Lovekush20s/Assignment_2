#include <bits/stdc++.h>
using namespace std;

bool isPossible(int n, vector<int>& arr, int trips, int mid) {
    long long total = 0;

    for(int i = 0; i < n; i++) {
        total += mid/arr[i];
        if(total >= trips) return true;
    }
    return false;
}

int minTime(int n, vector<int>& arr, int trips) {
    long long low = 1;
    long long hi = static_cast<long long>( *max_element(arr.begin(), arr.end())) * trips;

    while(low < hi) {
        long long mid = low + (hi - low) / 2;
        if(isPossible(n, arr, trips, mid)) {
            hi = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int trips;
    cin >> trips;

    cout << minTime(n, arr, trips) << endl;

    return 0;
}