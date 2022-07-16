class Solution {
    const int MOD = 1e9 + 7;
    int ways[50][50][51];

public:
    int findPaths(int m, int n, int k, int startRow, int startColumn) {
        memset(ways, -1, sizeof ways);
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        return findRecursive(startRow, startColumn, m, n, k, dirs);
    }
private:
    int findRecursive(int row, int col, int height, int width, 
                      int remainingMoves, vector<pair<int, int>>& dirs) {
        if(row < 0 || col < 0 || row >= height || col >= width) {
            return 1;
        }
        
        if(remainingMoves == 0) {
            return ways[row][col][remainingMoves] = 0;
        }
        
        if(ways[row][col][remainingMoves] != -1) {
            return ways[row][col][remainingMoves];
        }
        
        int res = 0;
        for(pair<int, int>& p : dirs) {
            int nrow = row + p.first;
            int ncol = col + p.second;
            res += findRecursive(nrow, ncol, height, width, remainingMoves - 1, dirs);
            if (res > MOD) {
                res %= MOD;
            }
        }
        return ways[row][col][remainingMoves] = res;
    }
};
