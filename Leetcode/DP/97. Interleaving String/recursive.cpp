class InterleavingString {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size();
        int b = s2.size();
        if(a + b != s3.size()) {
            return false;
        }
        
        vector<vector<int>> A(a+1, vector<int> (b+1));
        
        return helper(s1, s2, s3, A, 0, 0) == 1;
        
    }
private:
    int helper(string& s1, string& s2, string& s3, vector<vector<int>>& A, int a, int b) {
        if(a+b == s3.size()) {
            return 1;
        }
        if(A[a][b] != 0) {
            return A[a][b];
        }
        int l = 0, r = 0;
        if(a < s1.size() && s3[a+b] == s1[a]) {
            if(helper(s1, s2, s3, A, a+1, b) == 1)
                return 1;
        }
        if(b < s2.size() && s3[a+b] == s2[b]) {
           if(helper(s1, s2, s3, A, a, b+1) == 1)
               return 1;
        }
        return A[a][b] = 2;
    }
};
