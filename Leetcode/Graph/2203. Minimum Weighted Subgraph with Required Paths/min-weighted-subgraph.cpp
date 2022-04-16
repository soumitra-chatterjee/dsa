// q - 
// Return the minimum weight of a subgraph of the graph such that 
// it is possible to reach dest from both src1 and src2 
// via a set of edges of this subgraph. In case such a subgraph does not exist, return -1.
// 
// * select a middle point that connects all three nodes; For all such nodes 
// find the minimum possible total distance.
// 

class Solution {
public:
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        vector<vector<pair<int, int>>> adj(n);  
        vector<vector<pair<int, int>>> reverseAdj(n);  // reversed edge-directions 
        
        for(vector<int>& edge: edges) {
            int u = edge[0];
            int to = edge[1];
            int wt = edge[2];
            adj[u].emplace_back(to, wt);
            reverseAdj[to].emplace_back(u, wt);
        }
        
        vector<long> distFromSrc1(n, LONG_MAX);  // distances of all nodes from src1
        vector<long> distFromSrc2(n, LONG_MAX);  // distances of all nodes from src1
        vector<long> distToDest(n, LONG_MAX);    // all nodes distances towords destinaion
        
        findAllDistances(src1, adj, distFromSrc1);
        findAllDistances(src2, adj, distFromSrc2);
        findAllDistances(dest, reverseAdj, distToDest);
        
        long minWeight = LONG_MAX;
        for(int mid = 0; mid < n; mid++) {
            long x = distFromSrc1[mid];
            long y = distFromSrc2[mid];
            long z = distToDest[mid];
            if(x == LONG_MAX || y == LONG_MAX || z == LONG_MAX) {
                continue;
            }
            if(x + y + z < minWeight) {
                minWeight = x + y + z;
            }
        }
        
        if(minWeight == LONG_MAX) {
            return -1;
        }
        return minWeight;
    }
    
private:
    
    void findAllDistances(int src, vector<vector<pair<int, int>>>& adj, vector<long>& distance) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, src);
        distance[src] = 0;
        
        while(pq.size()) {
            int u = pq.top().second;
            int curr = pq.top().first;
            pq.pop();
            if(curr > distance[u]) {
                continue;
            }
            for(pair<int, int>& p: adj[u]) {
                int to = p.first;
                int wt = p.second;
                if(distance[to] > distance[u] + wt) {
                    distance[to] = distance[u] + wt;
                    pq.emplace(distance[to], to);
                }
            }
        }
    }
};
