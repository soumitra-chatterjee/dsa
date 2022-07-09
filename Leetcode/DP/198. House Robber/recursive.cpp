class Solution {
public:
    int rob(vector<int>& nums) {
        return robRecursive(0, nums);
    }
private:
    int robRecursive(int hs, vector<int>& nums) {
        
        int N = nums.size();
        if(hs >= N) {
            return 0;
        }
        int res = 0;
        for(int i = hs ; i < N ; i++) {
            res = max(res, nums[i] + robRecursive(i+2, nums));
        }
        return res;
    }
};
