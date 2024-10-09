class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;
        for(auto i: s) {
            if(i== '(') st.push(i);
            else if(!st.empty() && i == ')' && st.top() == '(') st.pop();
            else cnt++;
        }
        return st.size()+cnt;
    }
};