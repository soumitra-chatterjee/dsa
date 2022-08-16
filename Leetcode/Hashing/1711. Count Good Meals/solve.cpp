class Solution {
    const int MOD = 1e9 + 7;
public:
    int countPairs(vector<int>& A) {
        int N = A.size();
        unordered_map<int, int> cnt;
        int res = 0;
        for(int i = 0; i < N; i++) 
        {
            int val = A[i];
            int sum = 1;
            for(int e = 0; e < 22; e++) {
                int target = sum - val;
                res += cnt[target];
                res %= MOD;
                sum = sum << 1;
            }
            
            cnt[val]++;
            
        }
        return res;
    }
};
