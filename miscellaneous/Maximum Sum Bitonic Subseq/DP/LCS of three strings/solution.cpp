// similar to lcs of two strings
int LCS (string A, string B, string C) {
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();
    int dp[n1+1][n2+1][n3+1];
    
    for(int i = 0; i <= n1; i++) 
        for(int j = 0; j <= n2; j++) 
            for(int k = 0; k <= n3; k++) 
                dp[i][j][k] = 0;
       
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            for(int k = 0; k < n3; k++) {
                // 100, 010, 001, 110, 101, 011, /*111*/ 
                if(A[i] == B[j] && B[j] == C[k]) {
                    dp[i+1][j+1][k+1] = 1 + dp[i][j][k];
                }
                else {
                    int res = 0;
                    for(int mask = 1; mask <= 6; mask++) {
                        int f = (mask >> 0) & 1;
                        int s = (mask >> 1) & 1;
                        int t = (mask >> 2) & 1;
                        res = max(res, dp[i+f][j+s][k+t]);
                    }
                    dp[i+1][j+1][k+1] = res;
                }
            }
        }
    }
    return dp[n1][n2][n3];
}
