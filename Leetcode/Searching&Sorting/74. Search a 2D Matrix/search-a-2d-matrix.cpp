
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int H = matrix.size();
        int W = matrix[0].size();
        
        if(target < matrix[0][0] || target > matrix[H-1][W-1]) {
            return false;
        }
        
        // binary search over first element of each row
        int lowRow = 0;
        int highRow = H - 1;
        while(lowRow <= highRow) {
            int mid = lowRow + (highRow - lowRow) / 2;
            if(matrix[mid][0] == target) {
                return true;
            }
            else if(matrix[mid][0] < target) {
                lowRow = mid + 1;
            }
            else {
                highRow = mid - 1;
            }
        }
        // binary search over all columns of the 'high'-indexed row
        int low = 0; 
        int high = W - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(matrix[highRow][mid] == target) {
                return true;
            }
            else if(matrix[highRow][mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
};
