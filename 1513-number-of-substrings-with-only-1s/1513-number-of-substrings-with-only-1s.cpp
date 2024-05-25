class Solution {
public:
    int numSub(string s) {
        int mod = 1e9+7;
        int ans = 0;
        int cnt = 0;
        for(char i: s) {
            if(i == '1') cnt++;
            else {
                cnt = 0;
            }
            ans = (ans+cnt)%mod;
        }
        return ans;
    }
};