class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int n = s.size();
        stack<int> st;
        st.push(-1);
        for(int i = 0; i<n; i++) {
            if(s[i] == ')') {
                if(st.top() >= 0 && s[st.top()] == '(') st.pop();
                else st.push(i);
            }
            else st.push(i);
            ans = max(ans,i-st.top());
        }
        return ans;
    }
};