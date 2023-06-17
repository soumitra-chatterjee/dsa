class FindEventualSafeStates {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<bool> vis(N, false);
        vector<bool> path(N, false);
        vector<bool> res(N, true);
        vector<int> r;
        for(int i = 0; i < N; i++ ) {
            if(vis[i] == false) 
                dfs(i, graph, vis, path, res);
        }

        for(int i = 0; i < N; i++) {
            if(res[i] == true) 
                r.push_back(i);
        }
        return r;
    }
private:
    bool dfs(int i, vector<vector<int>>& g, vector<bool>& vis, vector<bool>& path, vector<bool>& res) {
        vis[i] = true;
        path[i] = true;
        for(int to : g[i]) {
            if(vis[to] == true) {
                if(path[to] == true || res[to] == false) {
                    path[i] = false;
                    return res[i] = false;
                }
            }
            else {
                if(dfs(to, g, vis, path, res) == false) {
                    path[i] = false;
                    return res[i] = false;
                } 
            }
        }
        path[i] = false;
        return true;
    }
};
