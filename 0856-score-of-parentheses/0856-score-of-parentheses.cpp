class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<pair<int,char>> st;
        for(auto &i: s) {
            if(i == '(') st.push({0,'('});
            else {
                int cnt = 0;
                int score = 0;
                while(!st.empty() && st.top().second == '1') {
                    score += st.top().first;
                    st.pop();
                    cnt++; 
                }
                st.pop();
                if(cnt >= 1) st.push({2*score,'1'});
                else {
                    st.push({1,'1'});
                }
            }
        }
        int ans = 0;
        while(!st.empty() && st.top().second == '1') {
            ans += st.top().first;
            st.pop();
        }
        return ans;
    }
};