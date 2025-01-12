class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> st,change;
        int n = s.size();
        if(n&1) return false;
        for(int i = 0; i<n; i++) {
            if(locked[i] == '0') change.push(i);
            else if(s[i] == '(') st.push(i);
            else {
                if(!st.empty()) st.pop();
                else if(!change.empty()) change.pop();
                else return false;
            }
        }
        while(!st.empty() && !change.empty() && st.top() < change.top()) {
            st.pop();
            change.pop();
        } 
        if(!st.empty() || (change.size() & 1)) return false;
        return true;
    }
};