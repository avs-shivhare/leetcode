class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,long long> mpp;
        long long ans = 0, sum = 0, less = 0;
        mpp[0] = 1;
        for(auto &i: nums) {
            if(i == target) {
                less += mpp[sum];
                sum++;
            }
            else {
                sum--;
                less -= mpp[sum];
            }
            mpp[sum]++;
            ans += less;
        }
        return ans;
    }
};