class MaximumScore {
public:
    int maxScore(vector<int>& points, int k) {
        int N = points.size();
        for(int i = 0; i < N; i++) {
            if(i == 0) continue;
            points[i] += points[i-1];
        }
        int res = 0;
        int subArrayLen = N - k;
        int totalSum = points[N-1];
        if(subArrayLen == 0) {
            return totalSum;
        }
        
        for(int l = 0 ; l + subArrayLen - 1 < N ; l++) {
            int subArraySum = points[l+subArrayLen-1] - (l == 0 ? 0 : points[l-1]);
            res = max(res, totalSum - subArraySum);
        }
        return res;
    }
};
