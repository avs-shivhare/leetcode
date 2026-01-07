class Solution {
public:
    long long minimumCost(string s, string t, int f, int sw, int c) {
        long long cnt1 = 0,cnt2 = 0;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            if(s[i] != t[i]) {
                if(s[i] == '0') cnt1++;
                else cnt2++;
            }
        }
        long long pair = min(cnt1,cnt2);
        pair = pair*min(2ll*f,1ll*sw);
        long long rem = abs(cnt1-cnt2);
        long long rcost = rem/2*min(2ll*f,1ll*sw+c);
        if(rem&1) rcost += f;
        return rcost+pair;
    }
};