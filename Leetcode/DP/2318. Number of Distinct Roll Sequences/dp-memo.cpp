class DistinctSequences {
    int MOD = 1e9 + 7;
    int dp[10001][7][8];

public:
    int distinctSequences(int n) {
        memset(dp, -1, sizeof dp);
        int res = 0;
        for(int dice = 1; dice <= 6; dice++) {
            res += seq(n, 1, dice, 7);
            res %= MOD;
        }
        return res;
    }
    
private: 
    int seq(int n, int pos, int p1, int p2) {
        if(dp[pos][p1][p2] != -1) 
            return dp[pos][p1][p2];
        
        if(n == pos) {
            return dp[pos][p1][p2] = 1;
        } 
        
        dp[pos][p1][p2] = 0;
        for(int dice = 1; dice <= 6; dice++) {
            if(dice != p2 && __gcd(dice, p1) == 1 && dice != p1) {
                dp[pos][p1][p2] = (dp[pos][p1][p2] + seq(n, pos+1, dice, p1)) % MOD;
            }
        }
        return dp[pos][p1][p2];
    }
};
