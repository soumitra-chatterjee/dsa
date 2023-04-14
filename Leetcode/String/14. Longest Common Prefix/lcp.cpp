class LCP {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int N = strs.size();
        string prefix = strs[0];
        int pLength = prefix.size();
        for(int index = 1; index < N; index++) {
            int j = 0;
            string match = strs[index];
            while(j < pLength && j < (int)match.size() && prefix[j] == match[j]) {
                j++;
            }
            pLength = j;
        }
        return prefix.substr(0, pLength);
    }
};
