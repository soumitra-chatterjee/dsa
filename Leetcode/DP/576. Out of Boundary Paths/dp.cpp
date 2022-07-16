class Solution {
    const int MOD = 1e9 + 7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int res = 0;
        vector<vector<int>> ways(m, vector<int>(n));
        vector<vector<int>> temp(m, vector<int>(n));
        ways[startRow][startColumn] = 1;
        
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        auto withinBounds = [&m, &n] (int& row, int& col) {
            return (row >= 0 && row < m && col >= 0 && col < n);
        };
        for(int k = 1; k <= maxMove; k++) {
            temp.clear();
            temp.resize(m, vector<int>(n));
            for(int row = 0; row < m; row++) {
                for(int col = 0; col < n; col++) {
                    if(row == 0) {
                        res = (res + ways[row][col]) % MOD;
                    }
                    if(col == 0) {
                        res = (res + ways[row][col]) % MOD;
                    }
                    if(row == m-1) {
                        res = (res + ways[row][col]) % MOD;
                    }
                    if(col == n-1) {
                        res = (res + ways[row][col]) % MOD;
                    }
                    for(auto& dir: dirs) {
                        int nrow = row + dir.first;
                        int ncol = col + dir.second;
                        if(withinBounds(nrow, ncol)) { 
                            temp[nrow][ncol] += ways[row][col];
                            temp[nrow][ncol] %= MOD;
                        }
                    }
                }
            }
            ways = temp;
        }
        return res;
    }
};
