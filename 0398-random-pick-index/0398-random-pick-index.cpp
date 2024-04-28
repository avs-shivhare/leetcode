class Solution {
public:
    unordered_map<int,vector<int>> mpp;
    Solution(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i<n; i++) {
            mpp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int val = rand()%mpp[target].size();
        return mpp[target][val];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */