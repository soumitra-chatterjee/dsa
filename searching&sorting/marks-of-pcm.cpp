//
// q - https://practice.geeksforgeeks.org/problems/marks-of-pcm2529/1
//


class Solution{
    public:
    void customSort (int phy[], int chem[], int math[], int N)
    {
        auto comp = [](vector<int>& a, vector<int>& b) {
            if(a[0] != b[0]) {
                return a[0] < b[0];
            }
            else if(a[1] != b[1]) {
                return a[1] > b[1];
            }
            else {
                return a[2] < b[2];
            }
        };
        
        vector<vector<int>> arr(N, vector<int> (3));
        for(int i = 0; i < N; i++) {
            arr[i][0] = phy[i];
            arr[i][1] = chem[i];
            arr[i][2] = math[i];
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        for(int i = 0; i < N; i++) {
            phy[i] = arr[i][0];
            chem[i] = arr[i][1];
            math[i] = arr[i][2];
        }
    } 
};
