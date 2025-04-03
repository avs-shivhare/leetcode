class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<long long> prefix(n,0),suffix(n,0);
        for(int i = 1; i<n; i++) {
            prefix[i] = max(prefix[i-1],(long long)nums[i-1]);
        }
        for(int i = n-2; i>0; i--) {
            suffix[i] = max(suffix[i+1],(long long)nums[i+1]);
            ans = max(ans,(prefix[i]-(long long)nums[i])*suffix[i]);
        }
        return ans;
    }
};