class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<bool> flag(n,false);
        flag[0] = true;
        for(int i = 1; i<n; i++) {
            if(nums[i-1] < nums[i]) flag[i] = true;
        }
        int l = 0, r = n-1;
        while(l<r && flag[l+1]) l++;
        while(l<r && flag[r-1]) r--;
        //cout<<l<<" "<<r<<endl;
        if(l == r || l == 0 || !flag[n-1]) return false;
        for(int i = l+1; i<r; i++) {
            if(nums[i-1] <= nums[i]) return false;
        } 
        return true;
    }
};