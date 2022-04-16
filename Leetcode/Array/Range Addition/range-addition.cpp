

class Solution {
public:
    /**
     * @param length: the length of the array
     * @param queries: query operations
     * @return: the modified array after all k operations were executed
     */
    vector<int> getModifiedArray(int length, vector<vector<int>> &queries) {
        vector<int> arr(length);
        for(vector<int>& q : queries) {
            int startIndex = q[0];
            int endIndex = q[1];
            int inc = q[2];
            arr[startIndex] += inc;
            if(endIndex < length - 1) {
                arr[endIndex + 1] -= inc;
            }
        }
        for(int i = 1; i < length; i++) {
            arr[i] = arr[i] + arr[i-1];
        }
        return arr;
    }
};
