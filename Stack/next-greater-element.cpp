// https://leetcode.com/problems/next-greater-element-i/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> &a, vector<int> &b) {
	vector<int> res(a.size(), -1);
	unordered_map<int, int> index; 
	for(int i = 0; i < a.size(); i++) {
		index[a[i]] = i + 1; // 1-indexed
	}
	
	stack<int> stk;
	for(int e: b) {
		while(stk.size() && e > stk.top()) {
			int x = stk.top();
			stk.pop();
			if(index[x]) {
				res[index[x] - 1] = e;
			}
		}
		if(stk.empty() || stk.top() > e) {
			stk.push(e);
		}
	}
	return res;
}

void solve() {
	int m, n;
	cin >> m >> n;
	vector<int> a(m), b(n);
	for(int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for(int j = 0; j < n; j++) {
		cin >> b[j];
	}
	vector<int> res = nextGreater(a, b);
	for(int x: res) {
		cout << x << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
