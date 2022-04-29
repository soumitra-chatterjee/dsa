// Every reversal is a "1 cost" operation, 
// if we dont reverse it is "0 cost" operation, 
// thus the problem can be transformed to a ...
// "finding path on a weighted undirected graph"

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, m;

void dijkstra(vector<vector<pii>> &adj, int src, int dest) {
    vector<int> d(n+1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(0, src);
    d[src] = 0;
    while(pq.size()) {
        int curr_node = pq.top().second;
        int len = pq.top().first;
        pq.pop();
        if(d[curr_node] != len) {
            continue;
        } 
        for(auto P : adj[curr_node]) {
            int next_node = P.first;
            int cost = P.second;
            if(cost + len < d[next_node]) {
                d[next_node] = cost + len;
                pq.emplace(d[next_node], next_node);
            }
        }
    }
    if(d[n] == INT_MAX) {
        cout << "-1\n";
    }
    else cout << d[n] << "\n";
}

int main() {
	cin >> n >> m;
	vector<vector<pii>> adj(n+1);
	for(int i = 0; i < m; i++) {
	    int v, to;
	    cin >> v >> to;
	    adj[v].emplace_back(to, 0);
	    adj[to].emplace_back(v, 1);
	}
	dijkstra(adj, 1, n);
	return 0;
}
