class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int m = pushed.size();
        int n = popped.size();
        int i = 0;
        int j = 0;
        while(j < n) {
            if(st.empty() or st.top() != popped[j]) {
                if(i == m) 
                    return false;
                st.push(pushed[i++]);
            }
            else {
                st.pop();
                j++;
            }
        }
        return true;
    }
};
