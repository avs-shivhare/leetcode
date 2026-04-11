class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mpp;
        int ans = 1e9;
        for(int i = 0; i<n; i++) {
            if(mpp[nums[i]].size() == 2) {
                int a = mpp[nums[i]][0],b = mpp[nums[i]][1];
                ans = min(ans,abs(a-b)+abs(b-i)+abs(i-a));
                mpp[nums[i]][0] = mpp[nums[i]][1];
                mpp[nums[i]][1] = i;
            } 
            else mpp[nums[i]].push_back(i);
        }
        if(ans >= 1e9) return -1;
        return ans;
    }
};