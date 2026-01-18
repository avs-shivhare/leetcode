class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        bool flag = true;
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++) {
            if(nums[i] != target[i]) {
                flag = false;
                mpp[nums[i]]++;
            }
        }
        if(flag) return 0;
        return mpp.size();
    }
};