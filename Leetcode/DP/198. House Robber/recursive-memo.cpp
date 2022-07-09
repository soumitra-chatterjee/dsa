class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> money(nums.size(), -1);
        return robRecursive(0, nums, money);
    }
private:
    int robRecursive(int hs, vector<int>& nums, vector<int>& money) {
        
        int N = nums.size();
        if(hs >= N) {
            return 0;
        }
        if(money[hs] != -1) {
            return money[hs];
        }
        int res = 0;
        for(int i = hs ; i < N ; i++) {
            res = max(res, nums[i] + robRecursive(i+2, nums, money));
        }
        return money[hs] = res;
    }
};
