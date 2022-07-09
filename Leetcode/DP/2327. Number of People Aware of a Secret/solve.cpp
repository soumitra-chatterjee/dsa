class NumberOfPeopleAware {
    const int MOD = 1e9+7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(2000); // new people
        dp[0] = 1;
        int res = 0;
        for(int day = 0; day < n; day++) {
            if(day + forget >= n) 
                res = (res + dp[day])%MOD;
            for(int v = day + delay; v < day + forget; v++ ) {
                dp[v] = (dp[v] + dp[day]) % MOD;
            }
        }
        return res;
    }
};
