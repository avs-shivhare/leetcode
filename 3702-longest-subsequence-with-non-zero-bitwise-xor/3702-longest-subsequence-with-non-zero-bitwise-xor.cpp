class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        bool flag = true;
        for(auto &i: nums) {
            if(i != 0) flag = false;
            x ^= i;
        }
        if(flag) return 0;
        if(x == 0) return nums.size()-1;
        return nums.size();
    }
};