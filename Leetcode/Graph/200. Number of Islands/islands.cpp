class Islands {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int N = grid.size();
        int M = grid[0].size();
        
        int count = 0;
        vector<pair<int, int>> dirs = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for(int row = 0; row < N; row++) {
            for(int col = 0; col < M; col++) {
                if(grid[row][col] == '1') {
                    dfs(row, col, N, M, grid, dirs);
                    count++;
                }
            }
        }
        
        return count;
    }
    
private: 
    void dfs(int row, int col, int height, int width, vector<vector<char>>& grid, vector<pair<int, int>>& dirs) {
		
        grid[row][col] = '0';
        for(pair<int, int> dir: dirs) {
            int nrow = row + dir.first;
            int ncol = col + dir.second;
            
            if(cell_is_invalid(nrow, ncol, height, width) || grid[nrow][ncol] == '0')
                continue;
            
            dfs(nrow, ncol, height, width, grid, dirs);
            
        }
    }
    
    bool cell_is_invalid(int row, int col, int height, int width) {
        return row < 0 || row >= height || col < 0 || col >= width;
    }
};
