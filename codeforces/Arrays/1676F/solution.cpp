// 1676F - Longest Strike
// https://codeforces.com/problemset/problem/1676/F

#include <bits/stdc++.h>
using namespace std;
 
void solve() {
	int n, k; 
	cin >> n >> k;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	sort(a.begin(), a.end());
	vector<int> b;
	int freq = 0;
	for(int i = 0; i < n; i++) {
		if(i == 0 || a[i-1] == a[i]) {
			freq++;
		} 
		else {
			if(freq >= k) 
				b.push_back(a[i-1]);
			freq = 1;			
		}
	}
	if(freq >= k)
		b.push_back(a[n-1]);
 
	// for(int x: b) cout << x << " "; cout<<endl;
	int l = -1, r = -1;
	int left = 0;
	int curr = 0, res = 0;
	for(int i = 0; i < b.size() ; i++) {
		if(i == 0 || b[i] == b[i-1]+1) {
			curr++;
			if(curr > res) {
				res = curr;
				l = left;
				r = i;
			}
		}
		else {
			curr = 1;
			left = i;
		}
	}
		
	 if(l == -1) puts("-1");
	 else cout << b[l] << " " << b[r] << endl;
 
}
		
int main() {
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
	return 0;
}
