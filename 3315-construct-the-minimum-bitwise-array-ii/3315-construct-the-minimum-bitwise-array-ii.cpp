class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        for(int i =0; i<n; i++) {
            if((nums[i]&1) == 0) continue;
            int last = -1;
            for(int j = 0; j<32; j++) {
                if(nums[i]&(1<<j)) last = j;
                else break;
            }
            int el = ~(1<<last);
            int x = nums[i]&el;
            if((x | (x+1)) == nums[i]) ans[i] = x;
        }
        return ans;
    }
};