class DecodeWays {
public:
    int numDecodings(string s) {
        int N = s.size();
        
        int cur = 1, next = 0, second_next = 0;
        for(int i = 0; i < N; i++) {
            if(s[i] != '0') {
                next += cur;
                if(i + 1 < N && (s[i] - '0') * 10 + (s[i+1] - '0') <= 26) {
                    second_next += cur;
                }
            }
            
            cur = next;
            next = second_next;
            second_next = 0;
            
        }
        return cur;
    }
};
