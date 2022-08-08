class PalindromePartitioningIV {
    
public:
    bool checkPartitioning(string s) {
        int N = s.length();
        vector<vector<bool>> isPal(N, vector<bool> (N));
        findPalin(s, isPal);
        for(int j = 0; j < N-2 ; j++) {
            for(int k = j+1; k < N-1 ; k++) {
                if(isPal[0][j] && isPal[j+1][k] && isPal[k+1][N-1]) {
                    return true;
                }
            }
        }
        return false;
    }
    
private: 
    void findPalin(string s, vector<vector<bool>>& isPal) {
        int N = s.length();
        for(int i = 0 ; i < N; i++ ) {
            int l = i;
            int r = i;
            while(l >= 0 && r < N) {
                if(s[l] != s[r]) {
                    break;
                }
                isPal[l][r] = true;
                l--;
                r++;
            }
            l = i; r = i+1;
            while(l >= 0 && r < N) {
                if(s[l] != s[r]) {
                    break;
                }
                isPal[l][r] = true;
                l--;
                r++;
            }
        }
    }
};
