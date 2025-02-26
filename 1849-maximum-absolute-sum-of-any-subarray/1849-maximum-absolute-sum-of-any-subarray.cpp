class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int sum = 0;
        for(auto i: nums) {
            sum += i;
            maxi = max(maxi,sum);
            if(sum < 0) sum = 0;
        }
        sum = 0;
        for(auto i: nums) {
            sum += i;
            mini = min(mini,sum);
            if(sum > 0) sum = 0;
        }
        return max(abs(mini),abs(maxi));
    }
};