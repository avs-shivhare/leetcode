class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        int x = 0;
        bool flag = true;
        for(auto i: nums) {
            x ^= i;
            if(i>0) flag = false;
        }
        if(flag) return 0;
        if(x == 0) return n-1;
        return n;
    }
};