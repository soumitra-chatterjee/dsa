class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if(N == 1) {
            return nums[0];
        }
        int res = 0;
        for(int start: {0, 1}) {
            int before_prev = 0;
            int prev = 0;
            for(int i = start; i < start + N-1; i++) {
                int temp = max(nums[i] + before_prev, prev);
                before_prev = prev;
                prev = temp;
            }
            res = max(res, prev);
        }
        
        return res;
    }
};
