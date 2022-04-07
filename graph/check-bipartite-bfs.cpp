// q - check whether a graph is a bipartite 
// * undirected graph with odd length cycle can not be bipartite 
// https://en.wikipedia.org/wiki/Bipartite_graph
// https://leetcode.com/problems/is-graph-bipartite/

#include<bits/stdc++.h>
using namespace std;

bool check(int src, vector<int> &color,const vector<vector<int>> &adj) {
	color[src] = 0;
	queue<int> q;
	q.push(src);
	while(q.size()) {
		int curr = q.front();
		q.pop();
		for(const int &e: adj[curr]) {
			if(color[e] == -1) {
				color[e] = 1 - color[curr];
				q.push(e);
			}
			else if(color[e] == color[curr]) {
				return false;
			}
		}
	}
	return true;
}

bool isBipartite(vector<vector<int>>& graph) {
	int N = graph.size();
	vector<int> color(N, -1);
	queue<int> q;
	for(int i = 0; i < N; i++) {
		if(color[i] != -1) {
			continue;
		}
		if(check(i, color, graph) == false) {
			return false;
		} 
	}
	return true;
} 

void solve() {
	// N -> no of nodes, E -> no of edges
	int N, E;
	cin >> N >> E;
	vector<vector<int>> edges(E, vector<int> (2)); // edges[i] = {u, v} -> undirected edge between u and v
	for(int i = 0; i < E; i++) {
		cin >> edges[i][0] >> edges[i][1];
	}
	
	// create adjacency list
	vector<int> adj(N);
	for(vector<int> &edge: edges) {
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}
	
	if(isBipartite(adj) {
		cout << "It is a bipartite graph" << endl;
	}
	else {
		cout << "Not a bipartite graph" << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
	
