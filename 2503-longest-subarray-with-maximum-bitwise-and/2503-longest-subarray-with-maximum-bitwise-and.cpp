class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int x = 0,cnt = 0;
        int maxi =0,mcnt =0;
        for(auto i: nums) {
            if(x == i) cnt++;
            else {
                cnt = 1;
                x = i;
            }
            if(x > maxi) {
                maxi = x;
                mcnt = cnt;
            }
            else if(x == maxi) mcnt = max(cnt,mcnt);
        }
        return mcnt;
    }
};