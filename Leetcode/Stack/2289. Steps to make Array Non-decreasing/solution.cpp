class Solution {
    const int INF = 1e9 + 1;
public:
    int totalSteps(vector<int>& nums) 
	{
        int N = nums.size();
		
        stack<pair<int, int>> stk;  // -> {val, count}
        stk.emplace(INF, 0);
        
	int result = 0;
        for(int i = N-1; i >= 0; i--) {
            int delCount = 0;
            while(nums[i] > stk.top().first) 
	    {
                int prevCount = stk.top().second;
                delCount = max(delCount+1, prevCount);
                stk.pop();
            }
            result = max(result, delCount);
            stk.emplace(nums[i], delCount);
        }
        return result;
        
    }
};
