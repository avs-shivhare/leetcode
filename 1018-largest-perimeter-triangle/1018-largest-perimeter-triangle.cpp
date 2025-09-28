class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = n-1; i>=0; i--) {
            int l = 0, r = i-1;
            while(l<r) {
                int sum = nums[l]+nums[r];
                if(sum > nums[i]) {
                    ans = max(ans,sum+nums[i]);
                }
                l++;
            }
        }
        return ans;
    }
};