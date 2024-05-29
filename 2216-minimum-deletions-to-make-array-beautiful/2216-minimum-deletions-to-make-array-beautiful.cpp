class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i =0;
        while(i<nums.size()) {
            if((i&1) == 0) {
                if(i+1 < nums.size() && nums[i] == nums[i+1]) {
                    nums.erase(nums.begin()+i);
                    ans++;
                }
                else i++;
            }
            else i++;
        }
        if(nums.size() & 1) return ans+1;
        return ans;
    }
};