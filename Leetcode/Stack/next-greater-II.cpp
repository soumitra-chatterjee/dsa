// q - find the next greater element for each element
// in a circular array, if not found, put -1 in output array
// (lc - 503)

class Solution {
public:
	int nextGreaterInCircularArray(vector<int>& arr) {
		int N = arr.size();
		vector<int> res(N, -1);
		stack<int> st; // st will contain indices of arr elements
		for(int x: {0,1}) {
			for(int i = 0; i < N; i++) {
				int curr = arr[i];
				while(!st.empty() && curr > arr[st.top()]) {
					int index = st.top();
					st.pop();
					res[index] = curr;
				}
				if(res[i] == -1) {
					st.push(i);
				}
			}
		}
		return res;
	}
}; 
