class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        int before_prev = 0;
        int prev = 0;
        for(int x: nums) {
            int temp = max(x + before_prev, prev);
            before_prev = prev;
            prev = temp;
        }
        return prev;
    }
};
