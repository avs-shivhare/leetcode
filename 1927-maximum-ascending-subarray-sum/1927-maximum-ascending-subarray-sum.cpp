class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int el = 0,sum = 0,ans = 0;
        for(auto i: nums) {
            if(el < i) {
                sum += i;
            }
            else sum = i;
            el = i;
            ans = max(ans,sum);
        }
        return ans;
    }
};