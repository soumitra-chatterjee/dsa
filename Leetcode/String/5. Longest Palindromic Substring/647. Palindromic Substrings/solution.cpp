class PalindromicSubstrings {
public:
    int countSubstrings(string s) {
        int N = s.size();
        int res = 0;
        for(int i = 0; i < N; i++) {
            int l1 = i, r1 = i;
            while(l1 >= 0 && r1 < N && s[l1] == s[r1]) {
                res++;
                l1--;
                r1++;
            }
            int l2 = i, r2 = i+1;
            while(l2 >= 0 && r2 < N && s[l2] == s[r2]) {
                res++;
                l2--;
                r2++;
            }
        }
        return res;
    }
};
