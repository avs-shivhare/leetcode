class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum =0;
        int ans =0;
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i =0; i<n; i++) {
            if(nums[i] == 0) {
                sum += -1;
            }
            else sum += 1;
            if(sum == 0) {
                ans = max(ans,i+1);
            }
            else if(mpp.find(sum) != mpp.end()) {
                ans = max(ans,i-mpp[sum]);
            }
            else mpp[sum] = i;
        }
        return ans;
    }
};