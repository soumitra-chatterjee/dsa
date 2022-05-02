class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefix(N); // prefix sum
        for(int i = 0; i < N; i++) {
            prefix[i] = (i > 0? prefix[i-1] : 0) + nums[i];
        }
        for(int i = 0; i < N; i++) {
            int leftSum = (i == 0? 0 : prefix[i-1]);
            int rightSum = (i == N-1? 0 : (prefix[N-1] - prefix[i]));
            if(leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};
