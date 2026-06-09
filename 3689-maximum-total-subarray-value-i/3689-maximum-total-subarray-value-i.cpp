class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini = 1e18,maxi = -1e18;
        for(auto &i: nums) {
            mini = min(mini,1ll*i);
            maxi = max(maxi,1ll*i);
        }
        return (maxi-mini)*k;
    }
};