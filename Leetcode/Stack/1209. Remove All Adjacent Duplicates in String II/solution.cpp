
class Solution {
public:
   string removeDuplicates(string s, int k) {
        string res = "";
        vector<pair<char, int>> stk;  // {prev distinct character, count}
        
		for(char& c: s) {
            if(!stk.empty() && c == stk.back().first) {
                stk.back().second += 1;
                if(stk.back().second == k) {
                    stk.pop_back();
                }
            }
            else {
                stk.push_back({c, 1});
            }
        }
        for(auto& pr : stk) {
            res.append(pr.second, pr.first);
        }
        return res;
    }
};
