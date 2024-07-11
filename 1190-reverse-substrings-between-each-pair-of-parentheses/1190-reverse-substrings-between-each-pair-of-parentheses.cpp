class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char i: s) {
            if(i == ')') {
                string temp = "";
                while(!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
                for(char x: temp) st.push(x);
            }
            else {
                st.push(i);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};