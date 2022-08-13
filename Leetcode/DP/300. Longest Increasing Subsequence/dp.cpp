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
	
};
