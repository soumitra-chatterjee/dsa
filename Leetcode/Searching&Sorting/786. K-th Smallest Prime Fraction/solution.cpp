class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int N = arr.size();
        // sort(arr.begin(), arr.end());
        double low = (double) arr[0] / arr[N-1];
        double high = 1;
        while(low <= high) {
            double mid = (low + high) / 2;
            vector<int> res = search(arr, N, mid);
            int count = res[0];
            int numr = res[1];
            int deno = res[2];
            if(count == k) {
                return {numr, deno};
            }
            else if(count < k) {
                low = mid;
            }
            else {
                high = mid;
            }
        }
        return {};
    }
private:
    vector<int> search(vector<int>& A, int N, double mid) {
        int i = 0;
        int count = 0;
        int numr = A[0];
        int deno = A[N-1];
        for(int j = 1; j < N; j++) {
            while( i < j && A[i] <= mid * A[j]) {
                if(A[i] * deno > A[j] * numr) {
                    numr = A[i];
                    deno = A[j];
                }
                i++;
            }
            count += i;
        }
        return {count, numr, deno};
    }
};
