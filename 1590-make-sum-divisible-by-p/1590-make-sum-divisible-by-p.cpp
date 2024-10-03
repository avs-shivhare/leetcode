class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(auto i: nums) {
            sum += i;
        }
        int rem = sum%p;
        //cout<<sum<<endl;
        if(rem == 0) return 0;
        int ans = nums.size();
        int n = nums.size();
        unordered_map<int,int> mpp;
        long long prefix = 0;
        mpp[0] = -1;
        for(int i =0; i<n; i++) {
            prefix += nums[i];
            int curr = prefix%p;
            if(mpp.count((curr-rem+p)%p)) {
                ans = min(i-mpp[(curr-rem+p)%p],ans);
            }
            mpp[curr] =i;
        }
        if(ans == n) return -1;
        return ans;
    }
};