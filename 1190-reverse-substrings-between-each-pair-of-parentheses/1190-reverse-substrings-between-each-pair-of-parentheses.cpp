class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.size();
        for(int i =0; i<n; i++) {
            if(s[i] == ')') {
                string temp = "";
                while(!st.empty() && st.top() != '(') {
                    temp = st.top()+temp;
                    st.pop();
                }
                if(!st.empty()) st.pop();
                reverse(temp.begin(),temp.end());
                //if(st.empty()) return temp;
                for(char c: temp) st.push(c);
            }
            else {
                st.push(s[i]);
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