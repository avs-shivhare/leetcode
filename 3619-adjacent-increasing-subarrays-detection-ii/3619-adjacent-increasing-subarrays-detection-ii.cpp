class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0),suffix(n,0);
        prefix[0] = 1;
        for(int i = 1; i<n; i++) {
            if(nums[i-1] < nums[i]) prefix[i] = prefix[i-1]+1;
            else prefix[i] = 1;
        }
        suffix[n-1] = 1;
        for(int i = n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) suffix[i] = suffix[i+1]+1;
            else suffix[i] = 1;
        }
        // for(auto i: suffix) cout<<i<<" ";
        // cout<<endl;
        int ans = 0;
        for(int i = 0; i<n-1; i++) {
            ans = max(ans,min(prefix[i],suffix[i+1]));
        }
        return ans;
    }
};