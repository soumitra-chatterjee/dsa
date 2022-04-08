// q - find all the distinct triplets that give the sum equal to zero 
// *
// https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeeSum(vector<int>& A) {
	int n = A.size();
	// store frequencies of occurance in a hash-map
	unordered_map<int, int> freq;  
	set<vector<int>> s;
	for(int x: A) {
		freq[x]++;
	}
	
	for(int i = 0; i < n-2; i++) {

		freq[A[i]]--;

		for(int j = i+1; j < n; j++) {

			freq[A[j]]--;
			int req = 0 - (A[i] + A[j]);
			if(freq[req] != 0) {
				vector<int> tmp = {A[i], A[j], req};
				sort(tmp.begin(), tmp.end());
				s.insert(tmp);
			}
			freq[A[j]]++;
		}

		freq[A[i]]++;
	}
	return vector<vector<int>>(s.begin(), s.end());
}


void solve() {
	
	vector<int> a;
	int n, x;
	cin >> n;
	while(n--) {
		cin >> x;
		a.push_back(x);
	}
	vector<vector<int>> res = threeSum(a);
		
	for(vector<int> &v: res) {
		for(int &e: v) {
			cout << e << " ";
		}
		cout << endl;
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
