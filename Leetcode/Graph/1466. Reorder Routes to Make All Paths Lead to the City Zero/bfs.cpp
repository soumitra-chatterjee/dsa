class ReorderRoutes {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> G[n]; // adjacency list
        set<int> d[n];  // lookup set for directions
        
        for(vector<int>& v: connections) {
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
            d[v[0]].insert(v[1]);
        }
        
        int cnt = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(-1, 0));
        
        while(q.empty() == false) {
            int prev = q.front().first;
            int cur = q.front().second;
            q.pop();
            for(int next: G[cur]) {
                if(next == prev) {
                    continue;
                }
                if(d[cur].find(next) != d[cur].end()) {
                    cnt++;
                }
                q.push(make_pair(cur, next));
            }
        }
        return cnt;
    }
};
