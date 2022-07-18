class SubMatrixSum {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int H = matrix.size();
        int W = matrix[0].size();
        
        for(int row = 1; row < H; row++) {
            for(int col = 0; col < W; col++) {
                matrix[row][col] += matrix[row-1][col];
            }
        }
        unordered_map<int, int> freq;
        int res = 0;
        for(int r1 = 0; r1 < H; r1++) {
            for(int r2 = r1; r2 < H; r2++) {
                freq.clear();
                freq[0] = 1;
                int prefix = 0, find;
                for(int col = 0; col < W; col++) {
                    prefix += matrix[r2][col] - ( r1 > 0 ? matrix[r1-1][col] : 0);
                    find = prefix - target;
                    if(freq[find] != 0) {
                        res += freq[find];
                    }
                    freq[prefix] += 1;
                }
            }
        }
        
        return res;
        
    }
};
