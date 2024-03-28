class Solution {
public:
    //brute force solution but It give TLE so avoid this solution 
    // int longestOnes(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int ans = 0;
    //     for(int i =0;i<n; i++) {
    //         int zero = 0;
    //         int cnt =0;
    //         for(int j =i;j<n; j++) {
    //             if(nums[j] == 0) zero++;
    //             if(zero <=k) {
    //                 cnt++;
    //                 ans = max(ans,cnt);
    //             }
    //             else break;
    //         }
    //     }
    //     return ans;
    // }

    // better solution with O(2n) time complexity
    // int longestOnes(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int l = 0,r= 0;
    //     int ans = 0;
    //     int zero = 0;
    //     while(r<n) {
    //         if(nums[r] == 0) {
    //             zero++;
    //         }
    //         if(zero > k) {
    //             if(nums[l] == 0) zero--;
    //             l++;
    //         }
    //         if(zero <= k) ans = max(ans,r-l+1);
    //         r++;
    //     }
    //     return ans;
    // }

    //Optimal solution with O(n) time complexity
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0,r= 0;
        int ans = 0;
        int zero = 0;
        while(r<n) {
            if(nums[r] == 0) {
                zero++;
            }
            while(zero > k) {
                if(nums[l] == 0) zero--;
                l++;
            }
            if(zero <= k) ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};