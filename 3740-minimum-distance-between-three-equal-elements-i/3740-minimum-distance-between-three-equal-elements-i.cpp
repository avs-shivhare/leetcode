class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        int n = nums.size();
        int ans = 1e9;
        for(int i = 0; i<n; i++) {
            if(mpp[nums[i]].size() == 2) {
                ans = min(ans,abs(mpp[nums[i]][0]-mpp[nums[i]][1])+abs(mpp[nums[i]][1]-i)+abs(i-mpp[nums[i]][0]));
                mpp[nums[i]][0] = mpp[nums[i]][1];
                mpp[nums[i]][1] = i;
            }
            else mpp[nums[i]].push_back(i);
        }
        if(ans >= 1e9) return -1;
        return ans;
    }
};