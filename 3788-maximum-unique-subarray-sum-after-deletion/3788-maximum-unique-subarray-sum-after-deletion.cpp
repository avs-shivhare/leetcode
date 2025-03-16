class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int sum = 0;
        int ans = -1e9;
        for(auto i: nums) {
            ans = max(ans,i);
            if(i < 0) {

            }
            else if(mpp.count(i) == 0) {
                sum += i;
                mpp[i]++;
            }
        }
        if(mpp.size() > 0) ans = max(ans,sum);
        return ans;
    }
};