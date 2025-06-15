class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long ans = -1e18;
        int l = 0,r = 0;
        int n = nums.size();
        priority_queue<long long> maxi;
        priority_queue<long long,vector<long long>,greater<long long>> mini;
        while(r<n) {
            while(l<=r && r-l+1 >= m)  {
                maxi.push(nums[l]);
                mini.push(nums[l]);
                l++;
            }
            if(r-l+1 >= m-1 && !maxi.empty() && !mini.empty()) {
                ans = max({ans,maxi.top()*(long long)nums[r],mini.top()*(long long)nums[r]});
            }
            r++;
        }
        return ans;
    }
};