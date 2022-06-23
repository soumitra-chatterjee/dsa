
class Solution {
public:
    string removeDuplicates(string s, int k) 
	{
		string res;

		// stack will contain index, count pair
		// stack -> {last distinct character index, duplicate count}
		stack<pair<int, int>> count;

		for(int i = 0; i < s.size(); i++) {
			if(i == 0 || count.empty() || s[i] != s[count.top().first]) {
			count.emplace(i, 1);
			res.push_back(s[i]);
			}
			else {
				count.top().second += 1;
				res.push_back(s[i]);
				if(count.top().second == k) {
					for(int i = 1; i <= k; i++) {
						res.pop_back();
					}
					count.pop();
				}
			}
		}
		return res;
    }
};
