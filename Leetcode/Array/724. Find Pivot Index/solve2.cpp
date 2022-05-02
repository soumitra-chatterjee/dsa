class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int N = nums.size();
        int total = 0;
        for(int i = 0; i < N; i++) {
            total += nums[i];
        }
        int leftSum = 0;
        for(int i = 0; i < N; i++) {
            if(total - nums[i] == 2 * leftSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
