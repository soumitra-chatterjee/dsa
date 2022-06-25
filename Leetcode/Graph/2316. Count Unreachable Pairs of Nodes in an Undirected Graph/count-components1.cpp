class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector<int> adj[n];
        make_list(adj, edges);
        
        vector<int> count;
        vector<bool> vis(n);
        find_component_sizes(count, adj, vis, n);
        
        int total_components = count.size();
        
        long long int sum = 0;
        long long int rem = 0;
        for(int i = 0; i < total_components; i++) {
            long long right = n - count[i] - rem;
            right *= count[i];
            sum += right;
            rem += count[i];
        }
        return sum;
    }
    
private:
    void make_list(vector<int> adj[], vector<vector<int>>& edges) {
        // creates the adjacency list for undirected graph
        for(auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
    }
    
    void find_component_sizes(vector<int>& res, vector<int> adj[], vector<bool>& vis, int n) 
    {
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(vis[i]) {
                continue;
            }
            vis[i] = true;
            q.push(i);
            int cnt = 1;
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                for(int x: adj[curr]) {
                    if(vis[x]) 
                        continue;
                    q.push(x);
                    vis[x] = true;
                    cnt++; // when i find an element in the same component
                }
            }
            res.push_back(cnt);
        }
    }
    
    
};
