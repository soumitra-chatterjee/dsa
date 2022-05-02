class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int front = 0, it = 0; it < nums.size(); ++it) {
            if(nums[it] % 2 == 0) {
                swap(nums[front++], nums[it]);
            }
        }
        return nums;
    }
};
