class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        long long mini = 1e18;
        long long ans = -1;
        for(auto i: nums) {
            ans = max(ans,(long long)i-mini);
            mini = min(mini,(long long)i);
        }
        if(ans <= 0) return -1;
        return ans;
    }
};