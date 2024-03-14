class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum =0;
        int ans =0;
        unordered_map<int,int> mpp;
        int n=nums.size();
        mpp[0] =1;
        for(int i =0; i<n; i++) {
            sum += nums[i];
            
            //if(sum == goal) ans +=1;
            if(mpp.find(sum-goal) != mpp.end()) {
                ans += mpp[sum-goal];
                // mpp[sum-goal]++;
            }
            mpp[sum]++;
        }
        return ans;
    }
};