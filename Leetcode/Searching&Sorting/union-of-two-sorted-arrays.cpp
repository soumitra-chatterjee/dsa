// find the union(elements in common) of two **sorted** arrays
// https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays/1

class Solution {
public:
    vector<int> unionOfArrays(vector<int>& a, vector<int>& b) {
    	int N = a.size();
		int M = b.size();
		int x = 0; // iterates over a
		int y = 0; // iterates over b
		vector<int> unionArr;
		
		auto isDifferent = [&unionArr] (int curr) {
			return (unionArr.empty() || unionArr.back() != curr);
		};
		
		while(x < N && y < M) {
			if(a[x] == b[y]) {
				if(isDifferent(a[x])) {
					unionArr.push_back(a[x]);
				}
				x++;
				y++;
			}
			else if(a[x] < b[y]) {
				int curr = a[x];
				if(isDifferent(curr)) {
					unionArr.push_back(curr);
				}
				x++;
			}
			else {
				int curr = b[y];
				if(isDifferent(curr)) {
					unionArr.push_back(curr);
				}
				y++;
			}
		}
		while(x < N) {
			if(isDifferent(a[x])) {
				unionArr.push_back(a[x]);
			}
			x++;
		}
		while(y < M) {
			if(isDifferent(b[y])) {
				unionArr.push_back(b[y]);
			}
			y++;
		}
		
		return unionArr;
	}
};
