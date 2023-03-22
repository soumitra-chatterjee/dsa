class MinPathBetweenTwoCities {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> G[n+1];
        for(vector<int>& v: roads) {
            G[v[0]].push_back(make_pair(v[1], v[2]));
            G[v[1]].push_back(make_pair(v[0], v[2]));
        }
        vector<bool> vis(n+1, false);
        vis[0] = true;
        
        int res = INT_MAX;
        dfs(1, res, G, vis);
        
        return res;
    }
private:
    void dfs(int u, int& res, vector<pair<int, int>> G[], vector<bool>& vis) {
        for(pair<int, int> p: G[u]) {
            res = min(res, p.second);
            int v = p.first;
            if(vis[v] == false) {
                vis[v] = true;
                dfs(v, res, G, vis);
            }
        }
    }
};

