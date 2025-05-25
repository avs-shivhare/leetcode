class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            char next = (((s[i]-'a')+1)%26)+'a';
            char prev = (((s[i]-'a')-1+26)%26)+'a';
            if(!st.empty() && (st.top() == prev || st.top() == next)) {
                st.pop();
            }
            else st.push(s[i]);
        }
        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};