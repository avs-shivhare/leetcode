class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            int temp = sum%k;
            if(mpp.find(temp) == mpp.end()) {
                mpp[temp] = i;
            }
            else if(i-mpp[temp] > 1) return true;
        }
        return false;
    }
};