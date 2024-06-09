class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> mpp;
        mpp[0]++;
        int sum = 0;
        for(int i =0; i<n; i++) {
            sum += nums[i];
            int temp = sum%k;
            if(temp < 0) temp = temp+k;
            ans += mpp[temp];
            mpp[temp]++;
        }
        return ans;
    }
};