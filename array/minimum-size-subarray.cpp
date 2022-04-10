//
// q - https://leetcode.com/problems/minimum-size-subarray-sum/
// 

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums, int N) {
	int lo = 0;
	int hi = 0;
	int sum = nums[0];
	int res = INT_MAX;
	while(hi < N) {
		if(sum >= target) {
			res = min(res, hi - lo + 1);
			sum -= nums[lo];
			lo++;
		}
		else if(sum < target) {
			hi++;
			if(hi < N) {
				sum += nums[hi];
			}
		}
	}
	return (res == INT_MAX) ? 0 : res;
}

void solve() {
	int N;
	cin >> N;
	vector<int> nums(N);
	for(int& e: nums) {
		cin >> e;
	}
	int target;
	cin >> target;
	cout << minSubArrayLen(target, nums, N) << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
