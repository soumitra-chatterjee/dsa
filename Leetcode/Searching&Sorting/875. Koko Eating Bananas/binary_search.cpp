class KokoEatingBananas {
    const int MAX_RATE = 1e9 + 1;
public:
    int minEatingSpeed(vector<int>& piles, int h) 
	{
        int l = 1;
        int r = MAX_RATE;
        while(l <= r) {
            int mid = l + (r - l)/2;
            long int time = 0;
            for(int p: piles) {
                time += (p + mid - 1)/mid;
            }
            if(time <= h) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};
