class Solution {

    vector<vector<int>> dp;
    string a;
    string b;
    
    int lcs(int x, int y) {
        if(dp[x][y] != -1) {
            return dp[x][y];
        }
        if(x == 0 || y == 0) {
            return 0;
        }
        if(a[x-1] == b[y-1]) {
            return dp[x][y] = 1 + lcs(x-1, y-1);
        }
        int first = lcs(x, y-1);
        int second = lcs(x-1, y);
        return dp[x][y] = max(first, second);
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int x = text1.size();
        int y = text2.size();
        dp.resize(x+1, vector<int>(y+1, -1));
        a = text1;
        b = text2;
        return lcs(x, y);
    }

};
