class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = -1e18;
        long long mini = 1e18;
        for(auto &i: nums) {
            maxi = max(maxi,i*1ll);
            mini = min(mini,i*1ll);
        }
        long long sum = maxi-mini;
        long long ans = sum*(long long)k;
        return ans;
    }
};