#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> span(n);
	stack<int> st;

	for(int i = 0; i < n; i++) {
		while(!st.empty() && arr[st.top()] <= arr[i]) {
			st.pop();
		}
		if(st.empty()) {
			span[i] = i + 1;
		} else {
			span[i] = i - st.top();
		}
		st.push(i);
	}

	for(int s : span) {
		cout << s << " ";
	}
	cout << "END" << endl;

	return 0;
}