class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = 0,maxi = 0;
        int n = nums.size();
        for(int i = 1; i<n; i++) {
            if(nums[mini] > nums[i]) mini = i;
            if(nums[maxi] < nums[i]) maxi = i;
        }
        if(mini == maxi) return min(mini+1,n-mini);
        return min({mini+1+(n-maxi),maxi+1+(n-mini),max(mini,maxi)+1,n-min(mini,maxi)});
    }
};