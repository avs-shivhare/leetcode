class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int cnt = 0;
        for(auto i: s) {
            if(ans.empty() || ans.back() != i) {
                cnt = 1;
                ans += i;
            }
            else if(ans.back() == i) {
                if(cnt < 2) {
                    ans += i;
                    cnt++;
                }
                else cnt++;
            }
        }
        return ans;
    }
};