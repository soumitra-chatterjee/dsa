class SumofSubarrayMins {
    const int MOD = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int N = arr.size();
        stack<pair<int, int>> stk;   // {value, index}
        stk.emplace(0, -1);
        vector<long long int> dp(N); // dp[x] -> sum of minimums of all subarrays that end at x index
        
        int res = 0;
        
        for(int i = 0; i < N; i++) {
            
            int curr_val = arr[i];
            while(!stk.empty() && curr_val <= stk.top().first) {
                stk.pop();
            }
            int prev_i = stk.top().second;
            int count = i - prev_i;
            dp[i] = (count * curr_val + (prev_i == -1 ? 0 : dp[prev_i])) % MOD;
            res = (res + dp[i]) % MOD;
            
            stk.emplace(curr_val, i);
        }
        return res;
        
    }
};
