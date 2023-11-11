class SlidingWindowMax {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N = nums.size();
        deque<int> dq;
        int r = 0;
        vector<int> res(N-k+1);

        for(int i = 0; i < k; i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res[r++] = nums[dq.front()];

        for(int i = k; i < N; i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            while(!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }
            dq.push_back(i);
            res[r++] = nums[dq.front()];
        }
        return res;
    }
};
