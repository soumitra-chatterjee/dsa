class Solution {
public:
    void solve(vector<vector<char>>& b) {
        int H = b.size();
        int W = b[0].size();
        vector<pair<int, int>> dirs = {{-1, 0},
                                       {0, 1},
                                       {1, 0},
                                       {0, -1}};
        for(int c = 0; c < W; c++) {
            if(b[0][c] == 'O')
                dfs(0, c, H, W, b, dirs);
            if(b[H-1][c] == 'O')
                dfs(H-1, c, H, W, b, dirs);
        }
        for(int r = 0; r < H; r++) {
            if(b[r][0] == 'O') 
                dfs(r, 0, H, W, b, dirs);
            if(b[r][W-1] == 'O') 
                dfs(r, W-1, H, W, b, dirs);
        }
        for(int row = 0; row < H; row++) {
            for(int col = 0; col < W; col++) {
                if(b[row][col] == 'O') 
                    b[row][col] = 'X';
                if(b[row][col] == '#') 
                    b[row][col] = 'O';
            }
        }
    }
private:
    void dfs(int row, int col, int H, int W, vector<vector<char>>& b, vector<pair<int,int>>& dirs) {
        if(!valid(row, col, H, W, b))
            return;
        b[row][col] = '#';
        for(pair<int, int>& dir: dirs) {
            int nrow = row + dir.first;
            int ncol = col + dir.second;
            dfs(nrow, ncol, H, W, b, dirs);
        }
    }
    
    bool valid(int row, int col, int H, int W, vector<vector<char>>& b) {
        return (row >= 0 && row < H && col >= 0 && col < W && b[row][col] == 'O');
    }
};
