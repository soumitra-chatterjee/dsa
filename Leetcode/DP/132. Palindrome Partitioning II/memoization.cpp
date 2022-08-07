class Solution {
public:
    int minCut(string s) {
        int N = s.size();
        vector<int> mem(N, -1);
        vector<vector<bool>> isPal(N, vector<bool> (N));
        palin(s, isPal);
        return dfs(s, 0, mem, isPal);
    }
private:
    int dfs(string s, int i, vector<int>& mem, vector<vector<bool>>& isPal) {
        if(i >= s.length() || isPal[i][s.length()-1]) {
            return 0;
        }
        if(mem[i] != -1) {
            return mem[i];
        }
        int res = INT_MAX;
        for(int x = i; x < s.length(); x++) {
            if(isPal[i][x]) {
                res = min(res, 1 + dfs(s, x+1, mem, isPal));
            }
        }
        return mem[i] = res;
    }
    
    void findPalin(string s, vector<vector<bool>>& isPal) {
        int N = s.size();
        for(int m = 0; m < N; m++) {
            int l = m;
            int r = m;
            while(l >= 0 && r < N) {
                if(s[l] != s[r]) {
                    break;
                }
                else {
                    isPal[l][r] = true;
                    l--;
                    r++;
                }
            }
            
            l = m;
            r = m+1;
            while(l >= 0 && r < N) {
                if(s[l] != s[r]) {
                    break;
                }
                else {
                    isPal[l][r] = true;
                    l--;
                    r++;
                }
            }
        }
    }
};
