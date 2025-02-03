class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt = 0,el = 0,ans = 0;
        for(auto i: nums) {
            if(el < i) {
                cnt++;
            }
            else cnt = 1;
            el = i;
            ans = max(ans,cnt);
        }
        cnt = 0,el = 1e9;
        for(auto i: nums) {
            if(el > i) {
                cnt++;
            }
            else cnt = 1;
            el = i;
            ans = max(ans,cnt);
        }
        return ans;
    }
};