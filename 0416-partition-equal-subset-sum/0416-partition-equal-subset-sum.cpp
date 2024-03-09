class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2) return false;
        int target = totalSum/2;
        vector<bool> dp(target+1,false);
        if(nums[0] <= target){
            dp[0] = true;
            dp[nums[0]] = true;
        }
        for(int i =1; i<n; i++) {
            vector<bool> temp(target+1,false);
            if(nums[0]<= target) temp[0]= true;
            for(int j =1; j<= target; j++) {
                bool notTake = dp[j];
                bool take = false;
                if(nums[i] <= j) take = dp[j-nums[i]];
                temp[j] = take || notTake;
            }
            dp = temp;
        }
        return dp[target];
    }
};