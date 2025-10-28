class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
        int sum2 = 0;
        for(auto i: nums) {
            if(i == 0) {
                if(sum2 == sum) ans += 2;
                else if(abs(sum-sum2) == 1) ans++;
            }
            sum -= i;
            sum2 += i;
        }
        return ans;
    }
};