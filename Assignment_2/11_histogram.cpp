#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

ll largestRectangleArea(vector<ll>& heights) {
    stack<int> s;
    ll maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        ll currHeight = (i == n) ? 0 : heights[i];

        while (!s.empty() && currHeight < heights[s.top()]) {
            ll height = heights[s.top()];
            s.pop();
            ll width = s.empty() ? i : (i - s.top() - 1);
            maxArea = max(maxArea, height * width);
        }

        s.push(i);
    }

    return maxArea;
}

int main() {
    int n;
    cin >> n;
    vector<ll> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    cout << largestRectangleArea(heights) << endl;
    return 0;
}
