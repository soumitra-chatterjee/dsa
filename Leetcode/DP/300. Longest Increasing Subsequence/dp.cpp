class LIS {
public:
    int findLength(vector<int>& A) {
        int N = A.size();
        vector<int> dist(N, 1);
        int res = 1;
        for(int x = 0; x < N-1; x++) {
            for(int y = x+1; y < N; y++) {
                if(A[y] > A[x])  {
                    dist[y] = max( dist[y], dist[x] + 1);
                    res = max(res, dist[y]);
                }
            }
        }
        return res;
    }
	
	vector<int> findSeq(vector<int>& A) {
        int N = A.size();
        vector<int> dist(N, 1);
        vector<int> prev(N, -1);
        
		int len = 0, r = -1;
        for(int x = 0; x < N-1; x++) {
            for(int y = x+1; y < N; y++) {
                if(A[y] > A[x])  {
                    dist[y] = max( dist[y], dist[x] + 1);
                    prev[y] = x;
                    if(dist[y] > len) {
                        len = dist[y];
                        r = y;
                    }
                }
            }
        }
        
		vector<int> seq;
        for(int x = r; x >= 0 ; ) {
            seq.push_back(A[x]);
            x = prev[x];
        }
        reverse(seq.begin(), seq.end());
        return seq;
    }
};
