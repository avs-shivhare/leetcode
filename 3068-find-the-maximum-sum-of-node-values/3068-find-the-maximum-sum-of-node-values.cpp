class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0,cnt =0,mini = LLONG_MAX;
        for(auto i: nums) {
            if((i^k) > i) {
                sum += (i^k);
                cnt++;
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