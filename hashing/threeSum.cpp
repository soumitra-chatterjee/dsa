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
	
	// for better usability and responsiveness
	// take the input as string and process it
	// for example like "[1,2,4]"
	string inp;
	cin >> inp;
	
	if(inp.front() != '[' || inp.back() != ']') {
		cout << "wrong input format\n";
		return;
	}
	
	int L = inp.size();
	for(int i = 1; i < L - 1; ) {
		if(inp[i] == '') {
			cout << "wrong input format\n";
			return;
		}
		int j = i;
		while(inp[j+1] != ',') {
			j++;
		}
		
		string num_str = inp.substr(i, j - i + 1);
		
		int num = 0;
		for(char c: num_str) {
			if(c == ' ') {
				cout << num_str << "is not a single integer\n";
				return;
			}
			num = num * 10 + (c - '0');
		}
		
		a.push_back(num);
		
		// move the 'i' to the next number
		i = j + 2;
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
