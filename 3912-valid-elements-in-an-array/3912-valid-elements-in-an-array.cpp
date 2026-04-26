class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> ans;
        int maxi = -1e9;
        int n = nums.size();
        vector<int> suffix(n,-1e9);
        for(int i = n-2; i>=0; i--) {
            suffix[i] = max(suffix[i+1],nums[i+1]);
        }
        for(int i = 0; i<n; i++) {
            if(maxi < nums[i] || nums[i] > suffix[i]) ans.push_back(nums[i]);
            maxi = max(maxi,nums[i]);
        }
        return ans;
    }
};