class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(auto &i: s) {
            if(i == ')' || i == '}' || i == ']') {
                if(st.empty() || (st.top() != '(' && i == ')') || (st.top() != '[' && i == ']') || (st.top() != '{' && i == '}')) return false;
                st.pop();
            }
            else st.push(i);
        }
        if(st.empty()) return true;
        return false;
    }
};