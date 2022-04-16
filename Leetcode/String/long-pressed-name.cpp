//
// find if it is possible that the 'typed' name can be a 
// possible alteration of the 'name' because of some keys getting long pressed
// 

#include <bits/stdc++.h>
using namespace std;


bool check(string name, string typed) {
	int n = name.size();
	int m = typed.size();
	if(n > m) {
		return false;
	}
	int i = 0;
	int j = 0;
	
	while(i < n and j < m) {
		if(name[i] == typed[j]) {
			i++;
			j++;
		}
		else if(i > 0 && name[i-1] == typed[j]) {
			j++;
		}
		else {
			return false;
		}
	}
	
	while(j < m) {
		if(typed[j] == name[n-1]) {
			j++;
		}
		else {
			return false;
		}
	}
	
	return i == n ? true : false;
}


void solve() {
	string name;
	string typed;
	cin >> name >> typed;
	
	if(check(name, typed)) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}
}

int main() {
	int t;
	cin >> t;
	while(t-- > 0) {
		solve();
	}
	return 0;
}
