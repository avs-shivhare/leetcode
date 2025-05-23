class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        long long mini = 1e18;
        int cnt = 0;
        for(auto i: nums) {
            if((i^k) > i) {
                cnt++;
                sum += (i^k);
                mini = min(mini,(long long)(i^k)-i);
            }
            else {
                sum += i;
                mini = min(mini,(long long)i-(i^k));
            }
        }
        if(cnt & 1) return sum-mini;
        return sum;
    }
};