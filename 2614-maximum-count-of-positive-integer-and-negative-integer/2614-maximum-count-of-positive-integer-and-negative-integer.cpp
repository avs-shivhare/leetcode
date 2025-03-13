class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cnt = upper_bound(nums.begin(),nums.end(),-1)-nums.begin();
        int cnt2 = upper_bound(nums.begin(),nums.end(),0)- nums.begin();
        int n = nums.size();
        return max(cnt,n-cnt2);
    }
};