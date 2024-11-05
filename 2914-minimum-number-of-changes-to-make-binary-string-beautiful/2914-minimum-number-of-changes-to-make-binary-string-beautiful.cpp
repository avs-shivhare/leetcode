class Solution {
public:
    int minChanges(string s) {
        char x = s[0];
        int cnt = 1;
        int ans = 0;
        int n = s.size();
        for(int i =1; i<n; i++) {
            if(x == s[i]) cnt++;
            else {
                if(cnt & 1) {
                    ans++;
                    cnt = 0;
                }
                else {
                    x = s[i];
                    cnt = 1;
                }
            }
        }
        if(cnt  & 1) ans++;
        return ans;
    }
};