class DecodeWays {
public:
    int numDecodings(string s) {
        vector<int> A(s.size(), -1);
        return decodeRecursiveWithCaching(0, s, A);
    }
private:
    int decodeRecursiveWithCaching(int i, string& s, vector<int>& A) {
        if(i == s.size()) {
            return 1;
        }
        if(A[i] != -1) {
            return A[i];
        }
        int res = 0;
        if(s[i] == '0') {
            return A[i] = 0;
        }
        res += decodeRecursiveWithCaching(i+1, s, A);
        if(i + 1 < s.size() && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26) {
            res += decodeRecursiveWithCaching(i+2, s, A);
        }
        
        return A[i] = res;
            
    }
};
