class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long ans = -1e16;
        int n = nums.size();
        int i = 0;
        while(i<n) {
            int l = i,r = i;
            long long mid = nums[r];
            while(r+1 < n && nums[r+1] < nums[r]) {
                mid += nums[r+1];
                r++;
            }
            if(r == i) {
                i++;
                continue;
            }
            long long lmax = -1e18,rmax = -1e18;
            long long left = 0,right = 0;
            while(l>0 && nums[l-1] < nums[l]) {
                left += nums[l-1];
                l--;
                lmax = max(lmax,left);
            }
            if(l == i) {
                i++;
                continue;
            }
            int temp = r;
            while(r+1<n && nums[r+1] > nums[r]) {
                right += nums[r+1];
                r++;
                rmax = max(rmax,right);
            }
            if(r == temp) {
                i++;
                continue;
            }
            //cout<<lmax<<" "<<rmax<<" "<<mid<<endl;
            ans = max(ans,lmax+rmax+mid);
            i = r;
        }
        return ans;
    }
};