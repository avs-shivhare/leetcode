class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        sort(nums.begin(),nums.end());
        int maxi = nums[n/2];
        long long ans  = 0;
        for(int i : nums) {
            ans += abs(maxi-i);
        }
        return ans;
    }
};