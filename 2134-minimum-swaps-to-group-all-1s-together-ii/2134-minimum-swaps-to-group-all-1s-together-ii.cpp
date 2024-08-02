class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        for(int i =0; i<n; i++) {
            if(nums[i]) cnt++;
        }
        int l =0,r =0;
        int cnt2 =0;
        int ans =n;
        while(r<2*n) {
            if(nums[r%n]) cnt2++;
            if(r-l+1 > cnt) {
                if(nums[l%n]) cnt2--;
                l++;
            }
            if(r-l+1 == cnt) {
                ans = min(ans,cnt-cnt2);
            }
            r++;
        }
        return ans;
    }
};