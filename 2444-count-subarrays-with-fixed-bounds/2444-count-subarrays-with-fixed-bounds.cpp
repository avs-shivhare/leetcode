class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       long long ans = 0;
       int n = nums.size();
       int bad = -1,left = -1,right =-1;
       for(int i =0; i<n; i++) {
        if(!(minK<= nums[i] && nums[i] <= maxK)) bad = i;
        if(nums[i] == minK) left = i;
        if(nums[i] == maxK) right =i;
        ans += max(0,min(left,right)-bad);
       } 
       return ans;
    }
};