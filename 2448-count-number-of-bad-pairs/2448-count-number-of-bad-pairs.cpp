class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long t = 0;
        long long ans = 0,t1 = 0;
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            ans += t;
            t++;
            if(mpp.count(nums[i]-i)) {
                t1 += mpp[nums[i]-i];
            }
            mpp[nums[i]-i]++;
        }
        return ans-t1;
    }
};