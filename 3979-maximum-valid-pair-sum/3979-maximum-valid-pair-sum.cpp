class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int  n = nums.size();
        priority_queue<pair<long long,int>> q;
        int l = 0, r= 0;
        long long ans = -1e18;
        while(r<n) {
            while(l<=r && r-l >= k) {
                q.push({nums[l],l});
                l++;
            }
            if(!q.empty())ans = max(ans,1ll*q.top().first+nums[r]);
            r++;
        }
        return ans;
    }
};