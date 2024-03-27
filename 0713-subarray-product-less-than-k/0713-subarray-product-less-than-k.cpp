class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        long long product = 1;
        if(k<=1) return 0;
        int r =0,l =0;
        while(r<n) {
            product *= nums[r];
            while(product >= k) product /= nums[l++];
            cnt +=1+(r-l);
            r++;
        }
        return cnt;
    }
};