class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(auto i: s) {
            if('a' <= i && i<= 'z') ans += i;
            else if(i == '*') {
                if(!ans.empty()) ans.pop_back();
            }
            else if(i == '#') ans += ans;
            else if(i == '%') reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};