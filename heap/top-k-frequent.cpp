// https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>
using namespace std;

// using priority queue
vector<int> topKFrequent(int n, vector<int>& nums, int k) {
	unordered_map<int, int> freq;
	priority_queue<pair<int, int>> pq;
	vector<int> unique;
	vector<int> res;
	for(int e: nums) {
		if(freq[e]==0) {
			unique.push_back(e);
		}
		freq[e]++;
	}
	for(int e : unique) {
		pq.push({freq[e], e});
	}
	while(k--) {
		res.push_back(pq.top().second);
		pq.pop();
	}
	return res;
}
// TC - O(MlogM), M is the number of unique numbers
// SC - O(M + M + M) for the freq vector, pq and unique vector


// using buckets
vector<int> topKFrequent2(int n, vector<int>& nums, int k) {
	unordered_map<int, int> map; // {num, freq }
	for(int num : nums) {
		map[num]++;
	}

	vector<vector<int>> bucks(n + 1);
	vector<int> res;
	for(auto it: map) {
		bucks[it.second].push_back(it.first);
	}
	for(int i = bucks.size() - 1 ; i >= 0 ; i--) {
		for(int j = 0; j < bucks[i].size(); j++) {
			res.push_back(bucks[i][j]);
			if(res.size() == k) {
				return res;
			}
		}
	}
	return res;
}
// TC - O(N)
// SC - O(N + M + M)  // for the bucks and the map


void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int& e: a) {
		cin >> e;
	}
	vector<int> res = topKFrequent2(n, a, k);
	for(int x: res) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		solve();
	}
	return 0;
}
