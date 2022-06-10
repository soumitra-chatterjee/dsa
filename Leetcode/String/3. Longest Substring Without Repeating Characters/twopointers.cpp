// 
// using two pointers 'left' and 'right' 
// for deleting repeatations and finding 
// repeatations in the possible substring s[left, right]
// 

class LongestSubstringWithoutRepeatingCharacters {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len == 0) {
            return 0;
		}
		
        vector<int> freq(256);
        int left = 0;
		int right = 0;
		int res = 0;
        
		while(right < len) {
            char curr = s[right];
            while(freq[curr] == 1) {
                freq[s[left]]--;
                left++;
            }
            freq[curr]++;
            res = max(res, right - left + 1);
            right++;
        }
        
		return res;
    }
};
