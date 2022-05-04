


class Solution {
public:
	int longestCommonSubsequence1(string text1, string text2) {
		if(text1.empty() or text2.empty()) {
			return 0;
		}
		if(text1[0] == text2[0]) {
			return 1 + longestCommonSubsequence(text1.substr(1), text2.substr(1));
		}
		return max(longestCommonSubsequence(text1.substr(1), text2), 
				  longestCommonSubsequence(text1, text2.substr(1)));
	}
	
	
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.empty() or text2.empty()) {
            return 0;
        }
        
        if(text1.back() == text2.back()) {
            text1.pop_back();
            text2.pop_back();
            return 1 + longestCommonSubsequence(text1, text2);
        }
        
        return max(longestCommonSubsequence(string(text1.begin(), text1.end() - 1), text2), 
                  longestCommonSubsequence(text1, string(text2.begin(), text2.end() - 1)));
    }
};
