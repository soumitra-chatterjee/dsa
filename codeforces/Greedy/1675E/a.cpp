#include <bits/stdc++.h>
using namespace std;
 
void solve() {
	int n, k;
   	cin >> n >> k;
	string s;
   	cin >> s;
	char ddc = 'a', rdc = '#', rdl = '#';
	
	for(int i = 0; i < n; i++) {
		if(s[i] <= ddc) {
			s[i] = 'a';
		}
		else {
		 	if(s[i] - ddc <= k) {
				k -= (s[i] - ddc);
				ddc = s[i];
				s[i] = 'a';
			}
			
			else if (rdc == '#' && k > 0) {
				rdc = s[i];
			   	rdl = s[i] - k;
				s[i] = rdl;
				k = 0;	
			}
			else if(k == 0 && s[i] >= rdl && s[i] <= rdc) {
				s[i] = rdl;
			}
		}
	}
 
	cout << s << endl;
}
 
int main() {
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
	return 0;
}
