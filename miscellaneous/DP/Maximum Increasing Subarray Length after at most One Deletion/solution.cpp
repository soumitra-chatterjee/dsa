#include <bits/stdc++.h>
using namespace std;

int length(int n, vector<int>& a) {
	vector<int> fp(n, 1);
	vector<int> sp(n, 1);
	for(int i = 1; i < n; i++) {
		if(a[i] > a[i-1]) {
			fp[i] += fp[i-1];
		}
	}
	for(int j = n-2; j >= 0; j--) {
		if(a[j] < a[j+1]) {
			sp[j] += sp[j+1];
		}
	}
	
	int res = 0;
	for(int i = 0; i < n; i++) {
		int incld = fp[i] + sp[i] - 1;
		int before = (i == 0 ? 0 : fp[i-1]);
		int after = (i == n-1 ? 0 : sp[i+1]);
		int excld;
		if(i == 0 || i == n-1 || a[i-1] < a[i+1]) {
			excld = before + after;
		}
		else if(a[i-1] > a[i+1]) {
			excld = max(after, before);
		}
		int curr = max(incld, excld);
		if(curr > res) {
			res = curr;
		}
	}
	return res;

}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << length(n, a) << endl;
	}
	return 0;
}
