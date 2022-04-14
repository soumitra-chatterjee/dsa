// Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, 
// return the number of tuples (i, j, k, l) such that:
// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
// https://leetcode.com/problems/4sum-ii/ 
// (lc - 454)

class Solution {
public: 
	int findCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		int count = 0;
		unordered_map<int, int> freq;
		for(int first: nums1) {
			for(int second: nums2) {
				int firstHalf = first + second;
				freq[firstHalf]++;
			}
		}
		for(int third: nums3) {
			for(int forth: nums4) {
				int requiredHalf = -(third + forth);
				count += freq[requiredHalf]; // frequency is zero if not present
			}
		}
		return count;
	}
};
		
	
