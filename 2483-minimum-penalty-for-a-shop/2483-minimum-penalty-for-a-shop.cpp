class Solution {
public:
    int bestClosingTime(string s) {
        int cnt = 0,cnt2 = 0;
        for(auto &i: s) {
            if(i == 'Y') cnt++;
        }
        int ans = 1e9,ind = 0;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            if(cnt2+cnt < ans) {
                ans = cnt2+cnt;
                ind = i;
            }
            if(s[i] == 'Y') cnt--;
            else cnt2++;
        }
        if(cnt2+cnt < ans) {
            ans = cnt2+cnt;
            ind = n;
        }
        return ind;
    }
};