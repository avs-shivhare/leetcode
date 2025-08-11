class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> temp = nums;
        sort(nums.begin(),nums.end());
        int x = INT_MAX;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] != temp[i]) x &= temp[i];
        }
        if(x == INT_MAX) return 0;
        return x;
    }
};