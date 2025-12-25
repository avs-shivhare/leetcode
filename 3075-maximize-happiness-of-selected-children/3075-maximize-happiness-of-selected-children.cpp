class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long ans = 0;
        sort(h.begin(),h.end(),greater<int>());
        long long cnt = 0;
        for(auto &i: h) {
            if(cnt >= k) break;
            ans += 1ll*max(0ll,i-cnt);
            cnt++;
        }
        return ans;
    }
};