class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j = 0;
        stack<int> st;
        for(int x: pushed) {
            st.push(x);
            while(st.size() and st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        if(st.empty()) {
            return true;
        }
        return false;
    }
};
