class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int cnt = 0;
        for(auto &i: s) {
            if(i == '(') {
                cnt++;
                if(cnt > 1) ans += i; 
            }
            else {
                cnt--;
                if(cnt >= 1) ans += i;
            }
        }
        return ans;
    }
};