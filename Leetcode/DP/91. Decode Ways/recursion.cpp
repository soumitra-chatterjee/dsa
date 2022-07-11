class DecodeWays {
public:
    int numDecodings(string s) {
        return decodeRecursive(0, s);
    }
private:
    int decodeRecursive(int i, string& s) {
        if(i == s.size()) {
            return 1;
        }
        if(s[i] == '0') {
            return 0;
        }
        int res = decodeRecursive(i+1, s);
        if(i + 1 < s.size() && (s[i] - '0') * 10 + (s[i+1] - '0') <= 26) {
            res += decodeRecursive(i+2, s);
        }
        return res;
    }
};
