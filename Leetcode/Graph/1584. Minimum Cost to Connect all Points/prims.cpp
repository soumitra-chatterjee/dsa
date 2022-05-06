struct Edge {
	int wt = INF;
	int par = -1;
	int x = 0;
	int y = 0;
};

const int INF = 1000000000;

class Solution {

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        int total_wt = 0;
        vector<Edge> min_e(N);
        vector<bool> selected(N);
        min_e[0].wt = 0;
        for(int i = 0; i < N; i++) {
            min_e[i].x = points[i][0];
            min_e[i].y = points[i][1];
        }
        
        for(int i = 0; i < N; i++) {
            int v = -1;
            for(int j = 0; j < N; j++) {
                if(!selected[j] && (v == -1 || min_e[j].wt < min_e[v].wt)) {
                    v = j;
                }
            }
            if(min_e[v].wt == INF) {
                cout << "Not possible" << endl;
                return -1;
            }
            selected[v] = true;
            total_wt += min_e[v].wt;
            for(int to = 0; to < N; ++to) {
                
                int dist = abs(min_e[v].x - min_e[to].x) + abs(min_e[v].y - min_e[to].y);
                
                if( dist < min_e[to].wt) {
                    min_e[to].par = v;
                    min_e[to].wt = dist;
                }
            }
        }
        return total_wt;
    }

};
