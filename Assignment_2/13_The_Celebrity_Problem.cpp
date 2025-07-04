#include<iostream>
#include<vector>
using namespace std;

bool check(vector<vector<int>> arr, int n, int i) {
	for(int j = 0; j < n; j++) {
		if(j == i) continue;
		if(arr[i][j] == 1 or arr[j][i] == 0) return false;
	}

	return true;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int c = 0;
	for(int i = 0; i < n; i++) {
		if(check(arr, n, i)) {
			c = i;
			break;
		}
	}

	if(c == 0) {
		cout << "No Celebrity" << endl;
	} else {
		cout << c << endl;
	}
	
	return 0;
}