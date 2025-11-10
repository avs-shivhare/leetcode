class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;
        unordered_map<int,vector<int>> mpp,mpp2;
        for(int i = n-1; i>=0; i--) {
            mpp2[nums[i]].push_back(i);
        }
        for(int i = 0; i<n; i++) {
            mpp2[nums[i]].pop_back();
            if(!mpp[nums[i]].empty() && !mpp2[nums[i]].empty()) {
                int a = mpp[nums[i]].back();
                int b = mpp2[nums[i]].back();
                ans = min(ans,abs(a-i)+abs(i-b)+abs(a-b));
            }
            mpp[nums[i]].push_back(i);
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};