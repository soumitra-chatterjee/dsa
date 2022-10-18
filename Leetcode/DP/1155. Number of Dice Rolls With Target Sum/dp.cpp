class Solution {
    typedef long long int ll;
    const int MOD = 1e9 + 7;
public:
    int numRollsToTarget(int n, int k, int target) {
        
        // vector<vector<int>> A(n+1, vector<int>(target+1, -1));
        // return dfs(A, n, target, k);
        
        vector<int> A(target+1);
        vector<int> B(target+1);
        A[0] = 1;
        for(int d = 1; d <= n; d++) {
            for(int t = 1; t <= target; t++) {
                ll res = 0;
                for(int x = 1; x <= k; x++) {
                    if(x <= t) {
                        res += A[t-x];
                    }
                }
                if(res > MOD) {
                    res %= MOD;
                }
                B[t] = res;
            }
            A = B;
            B.clear();
            B.resize(target+1);
        }
        return A[target];
    }
    
private: 
//     int dfs(vector<vector<int>>& A, int N, int T, int k) {
        
//         if(T < N) {
//             return 0;
//         }
//         if(T == N) {
//             return 1;
//         }
//         if(N == 0) {
//             return 0;
//         }
        
//         if(A[N][T] != -1) {
//             return A[N][T];
//         }
        
//         ll res = 0;
//         for(int d = 1; d <= k; d++) {
//             res += dfs(A, N-1, T-d, k);
//             if(res > MOD) {
//                 res %= MOD;
//             }
//         }
//         return A[N][T] = res;
//     }
};
