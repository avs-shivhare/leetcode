class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        int ans = 0;
        for(auto &i: s) {
            if(i == '(') cnt++;
            else cnt--;
            if(cnt < 0) {
                cnt = 0;
                ans++;
            }
        }
        ans += cnt;
        return ans;
    }
};