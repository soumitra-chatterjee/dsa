// q - find all the unique quadruplets that give the sum equal to a given target
// *
// https://leetcode.com/problems/4sum/

#include <bits/stdc++.h>
using namespace std;


// using hashmap, three iterators and a set of quadruplets
// tc - O(N^3 * logN)

vector<vector<int>> fourSum1(int n, vector<int>& nums, int target) {
	unordered_map<int, int> freq; 
	set<vector<int>> s;
	
	// keep no of occurances
	for(int x: nums) {
		freq[x]++;
	}

	for(int i = 0; i < n-3; i++) {
		freq[nums[i]]--;
		for(int j = i+1; j < n-2; j++) {
			freq[nums[j]]--;
			for(int k = j+1; k < n-1; k++) {
				freq[nums[k]]--;
				int find = target - (nums[i] + nums[j] + nums[k]);  
				// it'll overflow for (nums[i] + nums[j] + nums[k]) > INT_MAX
				if(freq[find] > 0) {
					vector<int> tmp = {nums[i], nums[j], nums[k], find};
					sort(tmp.begin(), tmp.end());
					s.insert(tmp);
				}
				freq[nums[k]]++;
			}
			freq[nums[j]]++;
		}
		freq[nums[i]]++;
	}
	return vector<vector<int>> (s.begin(), s.end());
}
// 


// using two iterators and two pointers method
// tc - O(N^3)
vector<vector<int>> fourSum(int n, vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	for(int i = 0; i < n-3 ; i++) {
		if(i != 0 && nums[i] == nums[i-1]) {
			continue;
		}
		for(int j = i+1; j < n-2; j++) {
			if((j != i + 1) && nums[j] == nums[j-1]) {
				continue;
			}
			int req = target - (nums[i] + nums[j]);
			int lo = j+1;
			int hi = n-1;
			while(lo < hi) {
				int sum = nums[lo] + nums[hi];
				if(sum == req) {
					vector<int> tmp = {nums[i], nums[j], nums[lo], nums[hi]};
					res.push_back(tmp);
					while(lo < hi && nums[lo] == nums[lo+1]) lo++;
					while(lo < hi && nums[hi] == nums[hi-1]) hi--;
					lo++;
					hi--;
				}
				else if (sum < req) {
					lo++;
				}
				else {
					hi--;
				}
			}
		}
	}
	return res;
}


void solve() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int& num: nums) {
		cin >> num;
	}
	int target;
	cin >> target;
	vector<vector<int>> res = fourSum(n, nums, target);
	for(vector<int> &v: res) {
		for(int e: v) {
			cout << e << " ";
		}
		cout << endl;
	}
}

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		solve();
	}
	return 0;
}
