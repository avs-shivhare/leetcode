class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        int maxi = -1e9;
        unordered_map<int,int> mpp;
        for(auto i: nums) {
            if(i >= 0 && mpp.count(i) == 0) {
                sum += i;
                mpp[i]++;
            }
            maxi = max(i,maxi);
        }
        if(sum == 0) return maxi;
        return sum;
    }
};