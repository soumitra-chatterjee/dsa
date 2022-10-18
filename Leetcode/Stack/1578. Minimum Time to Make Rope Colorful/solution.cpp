class Solution {
public:
    int minCost(string colors, vector<int>& T) {
        int res = 0;
        stack<int> st;
        for(int i = 0; i < (int)colors.length(); i++) {
            if(st.empty() || colors[st.top()] != colors[i] ) {
                st.push(i);
            }
            else if(T[st.top()] < T[i]) {
                res += T[st.top()];
                st.pop();
                st.push(i);
            }
            else {
                res += T[i];
            }
        }
        
        return res;
        
        // int res = 0; 
        // for(int i = 0; i < (int)colors.length()-1; i++) {
        //     if(colors[i] != colors[i+1]) 
        //         continue;
        //     res += min(T[i], T[i+1]);
        //     T[i+1] = max(T[i], T[i+1]);
        // }
        // return res;
    }
};
