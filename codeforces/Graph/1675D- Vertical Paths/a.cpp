#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		vector<int> par(n+1), tmp;
		vector<bool> vis(n+1), isPar(n+1);
		vector<vector<int>> res;
		
		for(int i = 1; i <= n; i++) {
			cin >> par[i];
			isPar[par[i]] = true;
		}
	
		if(n == 1) {
			res = {{par[1]}};
			goto out;
		}
		for(int i = 1; i<=n; i++) {
			if(isPar[i]) continue;
			int root = i;
			tmp.clear();
			while(!vis[root]) {
				vis[root] = true;
				tmp.push_back(root);
				root = par[root];
			}
			reverse(tmp.begin(), tmp.end());
			res.push_back(tmp);	
		}
	out: 
		cout << res.size() << endl;
		for(auto& v : res) {
			cout << v.size() << endl;
			for(int x : v) 
				cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}
