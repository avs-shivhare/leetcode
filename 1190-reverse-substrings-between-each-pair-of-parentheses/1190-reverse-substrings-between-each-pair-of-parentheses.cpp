class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(auto &i: s) {
            if(i == ')') {
                string rev = "";
                while(!st.empty() && st.top() != '(') {
                    rev += st.top();
                    st.pop();
                }
                st.pop();
                for(auto &j: rev) st.push(j);
            }
            else st.push(i);
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};