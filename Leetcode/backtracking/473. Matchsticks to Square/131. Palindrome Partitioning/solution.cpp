class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        vector<vector<string>> res;
        dfs(s, 0, tmp, res);
        return res;
    }
private:
    void dfs(string s, int i, vector<string>& tmp, vector<vector<string>>& res) {
        if(i >= s.size()) {
            res.push_back(tmp);
            return;
        }
        for(int x = i; x < s.size(); x++) {
            if(palin(s, i, x)) {
                tmp.push_back(s.substr(i, x - i + 1));
                dfs(s, x+1, tmp, res);
                tmp.pop_back();
            }
        }
    }
    bool palin(string s, int l, int r) {
        while(l <= r) {
            if(s[l] != s[r]) 
                return false;
            else {
                l++;
                r--;
            }
        }
        return true;
        
    }
};
