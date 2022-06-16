
class LIS {
public:
    string longestPalindrome(string s) {
        int N = s.length();
        string res = "";
        int len = 0;
		
		// for odd length substrings
        for(int i = 0; i < N; i++) {
            for(int d = 0; i-d >= 0 && i+d < N; d++) {
                if(s[i+d] != s[i-d]) {
                    break;
                }
                len = 2*d + 1;
                if(len > res.length()) {
                    res = s.substr(i-d, len);
                }
            } 
        }
		
		// for even length substring
        for(int i = 0; i < N; i++) {
            for(int d = 1; i-d+1 >= 0 && i+d < N; d++) {
                if(s[i-d+1] != s[i+d]) {
                    break;
                }
                len = 2*d;
                if(len > res.length()) {
                    res = s.substr(i-d+1, len);
                }
            }
        }
        return res;
    }
};
