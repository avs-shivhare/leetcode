class Solution {
public:
    // TLE
    // int maxSubarrayLength(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int ans = 0;
    //     for(int i =0;i<n; i++) {
    //         unordered_map<int,int> mpp;
    //         int cnt = 0;
    //         for(int j =i; j<n; j++) {
    //             mpp[nums[j]]++;
    //             if(mpp[nums[j]] <= k) {
    //                 cnt++;
    //                 ans = max(ans,cnt);
    //             }
    //             else break;
    //         }
    //     }
    //     return ans;
    // }

    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int l =0,r= 0;
        unordered_map<int,int> mpp;
        while(r<n) {
            mpp[nums[r]]++;
            if(mpp[nums[r]] > k) {
                while(nums[l] != nums[r]) mpp[nums[l++]]--;
                mpp[nums[l++]]--;
            }
            if(mpp[nums[r]] <= k) {
                ans = max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};