
// Suppose, there are n cities and for each pair of cities
// we are given the cost to build a road between them (if possible) 
// Build roads in minimum cost, such that 
// we can get from each city to every other city.


#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

struct Road {
    int cost = INF;
    int par = -1;
};

int prims(int n, vector<vector<int>>& adj) {
    int total_cost = 0;
    vector<Road> roads(n);
    vector<bool> repaired(n);
    roads[0].cost = 0;
    
	for(int i = 0; i < n; i++) {
        int parent = -1;
        for(int j = 0; j < n; j++) {
            if(!repaired[j] && (parent == -1 || roads[j].cost < roads[parent].cost)){
                parent = j;
            }
        }
        if(roads[parent].cost == INF ) {
            return -1;
        }
        repaired[parent] = true;
        total_cost += roads[parent].cost;
        for(int to = 0; to < n; to++) {
            if(adj[parent][to] < roads[to].cost) {
                roads[to] = {adj[parent][to], parent};
            }
        }
    }
    
	return total_cost;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> adj(n, vector<int>(n, INF));
        adj[0][0] = 0;
        for(int i = 0; i < e; i++) {
            int u, v, cost;
            cin >> u >> v >> cost;
            adj[u][v] = cost;
            adj[v][u] = cost;
        }
        cout << prims(n, adj) << endl;
    }
    return 0;
}
