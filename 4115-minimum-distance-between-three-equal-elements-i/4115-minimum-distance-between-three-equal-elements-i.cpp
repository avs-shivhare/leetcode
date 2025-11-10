class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = 1e9;
        int n = nums.size();
        unordered_map<int,vector<int>> mpp,mpp2;
        for(int i = n-1; i>=0; i--) {
            mpp2[nums[i]].push_back(i);
        }
        for(int i = 0; i<n; i++) {
            mpp2[nums[i]].pop_back();
            if(!mpp[nums[i]].empty() && !mpp2[nums[i]].empty()) {
                ans = min(ans,abs(mpp[nums[i]].back()-i)+abs(i-mpp2[nums[i]].back())+abs(mpp[nums[i]].back()-mpp2[nums[i]].back()));
            }
            mpp[nums[i]].push_back(i);
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};