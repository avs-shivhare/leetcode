class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& f) {
        int ans = 0,n = nums.size(),cnt = 0;
        unordered_map<int,int> mpp,mpp2,mpp3;
        for(int i = 0; i<n; i++) {
            if(nums[i] == f[i]) {
                cnt++;
                mpp3[nums[i]]++;
                ans = max(ans,mpp3[f[i]]);
            }
            mpp[nums[i]]++;
            mpp2[f[i]]++;
        }
        for(auto i: mpp) {
            if(i.second > n-mpp2[i.first]) return -1;
        }
        return max(ans,(cnt+1)>>1);
    }
};