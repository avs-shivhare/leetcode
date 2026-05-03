class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int odd = 0,even = 0;
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i = n-1; i>=0; i--) {
            if(nums[i]&1) {
                ans[i] = even;
                odd++;
            }
            else {
                ans[i] = odd;
                even++;
            }
        }
        return ans;
    }
};