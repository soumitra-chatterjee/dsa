// extension of the current question
// -> the string contains the new character '*', along with digits [0 - 9]
// '*' can be replaced by any one of the digits [1- 9]

class DecodeWays2 {
    const int MOD = 1e9+7;
public:
    int numDecodings(string s) {
        int N = s.length();
        long long int a = 1, b = 0, c = 0;
        for(int i = 0; i < N; i++) {
            if(a == 0) {
                return 0;
            }
            if(s[i] != '0') {
                if(s[i] == '1') {
                    b = (b + a) % MOD;
                    int mul = 1;
                    if(i < N-1 && s[i+1] == '*') {
                        mul = 9;
                    }
                    c = (c + a*mul) % MOD;
                }
                else if(s[i] == '2') {
                    b = (b + a) % MOD;
                    int mul = 1;
                    if(i < N-1 && s[i+1] == '*') {
                        mul = 6;
                    }
                    else if (i < N-1 && s[i+1] >= '7') {
                        mul = 0;
                    }
                    c = (c + a*mul) % MOD;
                }
                else if(s[i] == '*') {
                    b = (b + a*9) % MOD;
                    
                    int mul = 1;
                    if(i < N-1 && s[i+1] == '*') {
                        mul = 15;
                    }
                    else if(s[i+1] < '7') {
                        mul = 2;
                    }
                    c = (c + a*mul) % MOD;
                }
                else {
                    b = (b + a) % MOD;
                }
            }
            a = b;
            b = c;
            c = 0;
        }
        return a;
    }
};
