class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9+7;
        for(auto &i: queries) {
            int l = i[0];
            int r = i[1];
            int k = i[2];
            int v = i[3];
            for(int j = l; j<=r; j+=k) {
                nums[j] = (1ll*nums[j]*v)%mod;
            }
        }
        int ans = 0;
        for(auto &i: nums) {
            ans ^= i;
        }
        return ans;
    }
};