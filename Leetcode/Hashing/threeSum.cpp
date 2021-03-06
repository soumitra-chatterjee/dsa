// q - find all the distinct triplets that give the sum equal to zero 
// *
// https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum1(vector<int>& A) {
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

// the time complexity of the above approach is O(N^2 * logM)
// where M is the number of elements in our set 
// the space complexity will be O(N + M)


// better version - using two pointers method

vector<vector<int>> threeSum2(vector<int>& A) {
	vector<vector<int>> res;
	for(int i = 0; i < A.size() - 2; i++) {
		if(i != 0 && A[i] == A[i-1]) {
			continue;
		}
		int req = 0 - A[i];
		int low = i + 1;
		int high = A.size() - 1;
		while(low < high) {
			int sum = A[low] + A[high];
			if(sum == req) {
				vector<int> tmp = {A[i], A[low], A[high]};
				res.push_back(tmp);
				
				while(low < high && A[low] == A[low+1]) low++;
				while(low < high && A[high] == A[high-1]) high--;
				
				low++;
				high--;
			}
			else if(sum < req) {
				low++;
			}
			else {
				high--;
			}
		}
	}
	return res;
}
// Now the TC is O(N^2) and auxiliary Space is constant, O(1).
	
void solve() {
	
	vector<int> a;
	int n, x;
	cin >> n;
	while(n--) {
		cin >> x;
		a.push_back(x);
	}
	vector<vector<int>> res = threeSum2(a);
		
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
