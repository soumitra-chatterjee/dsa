#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 100001;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(N);
    vector<pii> ranges;
    int maxR = 0;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        A[l] += 1; 
        A[r+1] -= 1;
        ranges.emplace_back(l, r);
        if(r > maxR) maxR = r;
    }
    
    for(int i = 1; i <= maxR; i++) {
        A[i] += A[i-1];
    }
    
	// p1[x] -> count of Ks upto x index
    vector<int> p1(N); 
	// p2[x] -> count of (K+1)s upto x index
    vector<int> p2(N);
    
    for(int i = 1; i <= maxR; i++) {
        p1[i] = p1[i-1] + (A[i] == k ? 1 : 0);
        p2[i] = p2[i-1] + (A[i] == k+1 ? 1 : 0);
    }
    
    int res = 0;
    for(pii P: ranges) {
        int L = P.first;
        int R = P.second;
        int curr = p1[L-1] + (p1[maxR] - p1[R]) + (p2[R] - p2[L-1]);
        if(curr > res) {
            res = curr;
        }
    }
    cout << res << endl;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
	return 0;
}
