class Solution {
public:
    long long find(long long n) {
        long long rev = 0;
        while(n) {
            rev = rev*10+n%10;
            n /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = 1e9;
        unordered_map<long long,int> mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            long long rev = find(nums[i]);
            if(mpp.find(nums[i]) != mpp.end()) {
                ans = min(ans,i-mpp[nums[i]]);
            }
            mpp[rev] = i;
        }
        if(ans >= 1e9) return -1;
        return ans;
    }
};