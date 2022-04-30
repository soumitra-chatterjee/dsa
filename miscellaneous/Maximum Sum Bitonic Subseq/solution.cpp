// q - https://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence1857/1
// find the maximum sum bitonic subsequence from an array of N integers
// where a sequence is bitonic if it is first incresing then decreasing

class BitonicSum {
    vector<int> msi;
    vector<int> msd;
	
	// msi[i] is the maximum sum of the increasing
	// sub sequence that ends at index i
	// and msd[i] is the maximum sum of the decreasing
	// sub sequence that starts from index i
	
public: 
    int maxBitonicSum(int arr[] , int n )
    {
        msi.assign(n, 0);
        msd.assign(n, 0);
        for(int i = 0; i < n; i++) {
            msi[i] = arr[i];
            msd[i] = arr[i];
        }
        
        createMSI(arr, n);
        createMSD(arr, n);
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            int curr = msi[i] + msd[i] - arr[i];
            if(curr > res) {
                res = curr;
            }
        }
        return res;
    }

private:
    void createMSI(int arr[], int n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] > arr[j] && msi[j] + arr[i] > msi[i]) {
                    msi[i] = msi[j] + arr[i];
                }
            }
        }
    }
    void createMSD(int arr[], int n) {
        for(int i = n-2; i >= 0; i--) {
            for(int j = n-1; j > i; j--) {
                if(arr[i] > arr[j] &&  arr[i] + msd[j] > msd[i]) {
                    msd[i] = msd[j] + arr[i];
                }
            }
        }
    }
};
