class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ind = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] == 0) {
                ind = i;
                break;
            }
        }
        int ans1 = INT_MAX;
        for(int i = ind; i-ind<n-1; i++) {
            if(nums[i%n] >= nums[(i+1)%n]) {
                ans1 = -1;
                break;
            }
        }
        if(ans1 != -1) return min(ind,2+n-ind);
        int ans2 = INT_MAX;
        for(int i = ind; i>ind-n+1; i--) {
            if(nums[(n+i)%n] >= nums[(n+i-1)%n]) {
                ans2 = -1;
                break;
            }
        }
        if(ans2 != -1) return min(n-ind,ind+2);
        return -1;
    }
};