class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sum = 0,cnt = 0;
        int maxi = 0,len = 0;
        for(auto i: nums) {
            if(sum == i) {
                cnt++;
            }
            else {
                sum = i;
                cnt =1;
            }
            if(maxi < sum) {
                maxi = sum;
                len = cnt;
            }
            else if(maxi == sum && len < cnt) {
                len = cnt;
            }
        }
        return len;
    }
};