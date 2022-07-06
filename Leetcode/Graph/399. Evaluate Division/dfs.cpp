class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& a, vector<double>& val, vector<vector<string>>& q) {

        unordered_map<string, vector<pair<string, double>>> G;
        int N = a.size();
        for(int i = 0; i < N; i++) {
            G[a[i][0]].push_back(make_pair(a[i][1], val[i]));
            G[a[i][1]].push_back(make_pair(a[i][0], 1/val[i]));
        }
        
        vector<double> res;
         
        for(auto& vs: q) {
            
            string v = vs[0];
            string to = vs[1];
            unordered_set<string> vis;
            double ans = -1;
            auto it = G.find(v);
            if(it != G.end()) {
                dfs(v, to, G, vis, ans, 1);
            }
            res.push_back(ans);
        }
        return res;
    }
    void dfs(string& cur, string& to, unordered_map<string, vector<pair<string, double>>>& G, unordered_set<string>& vis, double& ans, double tmp) {
        if(vis.find(cur) != vis.end()) {
            return;
        }
        if(to == cur) {
            ans = tmp;
            return;
        }
        vis.insert(cur);
        for(auto& p: G[cur]) {
            dfs(p.first, to, G, vis, ans, tmp*(p.second));
        }
    }
    
};
