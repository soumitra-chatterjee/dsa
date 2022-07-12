class Solution {
public:
    bool makesquare(vector<int>& m) {
        int val = 0;
        for(int x: m) {
            val += x;
        }
        if(val % 4 != 0) {
            return false;
        }
        val = val / 4;
        sort(m.begin(), m.end(), greater<>());
        return ifPossible(0, m, val, 0, 0, 0, 0);
    }
private:
    bool ifPossible(int cur, vector<int>& m, int a, int top, int right, int bottom, int left) {
        
        if(top > a || right > a || bottom > a || left > a) {
            return false;
        }
        if(cur == m.size()) {
            return true;
        }
        if(ifPossible(cur + 1, m, a, top+m[cur], right, bottom, left) ||
           ifPossible(cur + 1, m, a, top, right+m[cur], bottom, left) ||
           ifPossible(cur + 1, m, a, top, right, bottom+m[cur], left) ||
           ifPossible(cur + 1, m, a, top, right, bottom, left+m[cur])) 
        {
            return true;
        }
        return false;    
    }
};
