class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n,false);
        int rem = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i]) {
                rem = (2*rem+1)%5;
            }
            else {
                rem = (2*rem)%5;
            }
            if(rem == 0) vis[i] = true;
        }
        return vis;
    }
};