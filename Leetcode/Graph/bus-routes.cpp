// q - bus routes
// * modified bfs
// https://leetcode.com/problems/bus-routes/submissions/

int minBusesToDest(vector<vector<int>>& routes, int src, int dest) {
	if(src == dest) {
		return 0;
	}
	unordered_map<int, vector<int>> busList; // {key->busStop, value->available_buses_from}
	int N = routes.size();
	for(int i = 0; i < N; i++) {
		int M = routes[i].size();
		for(int j = 0; j < M; j++) {
			int busStop = routes[i][j];
			busList[busStop].push_back(i);
		}
	}
	queue<pair<int, int>> q; // {current_bus_stop, level}
	unordered_map<int, bool> visitedBusStop;
	unordered_map<int, bool> visitedBus;
	q.push({src, 0});
	visitedBusStop[src] = true;
	while(q.size() > 0) {
		int curr = q.front().first;
		int level = q.front().second;
		if(curr == dest) {
			return level;
		}
		q.pop();
		for(int bus: busList[curr]) {
			if(visitedBus[bus] == true) {
				continue;
			}
			for(int nextStop: routes[bus]) {
				if(visitedBusStop[nextStop] == true) {
					continue;
				}
				int nextLevel = level + 1;
				q.push({nextStop, nextLevel});
				visitedBusStop[nextStop] = true;
			}
			visitedBus[bus] = true;
		}
	}
	return -1;
}
