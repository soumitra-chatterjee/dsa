class LongestPalindromicSubsequence {
public:
    int longestPalindromeSubseq(string s) {
        string a = s;
        string b = s;
        reverse(b.begin(), b.end());
        return longestCommonSubsequece(a, b);
    }
private:
    int longestCommonSubsequece(string& a, string& b) {
        int N = a.size();
        int res = 0;
        vector<int> first(N+1);
        vector<int> second(N+1);
        
        for(int r = 1; r <= N; r++) {
            for(int c = 1; c <= N; c++) {
                if(a[r-1] == b[c-1]) {
                    second[c] = 1 + first[c-1];
                }
                else {
                    second[c] = max(first[c], second[c-1]);
                }
                res = max(res, second[c]);
            }
            first = second;
            second.clear();
            second.resize(N+1);
        }
        return res;
    }
};
