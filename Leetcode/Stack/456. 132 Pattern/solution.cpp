class Solution {
public:
    bool find132pattern(vector<int>& nums) 
	{
        int N = nums.size();
		
		// minimum before current index
        int currMin = nums[0];
        
		// monotonic decreasing stack -> {val, minval}
		stack<pair<int, int>> stk;  
		
        for(int i = 1; i < N; i++) {
			int k_val = nums[i];
            while(!stk.empty() && k_val >= stk.top().first) {
                stk.pop();
			}
            if(stk.size() && stk.top().second < k_val) {
                return true;
			}
            stk.emplace(k_val, currMin);
            if(nums[i] < currMin) {
                currMin = k_val;
			}
        }
        return false;
    }
};
