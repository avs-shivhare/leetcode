class Solution {
public:
    long long reverse(long n) {
        long long ans = 0;
        while(n) {
            ans = ans*10ll+(n%10);
            n /= 10ll;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<long long,long long> mpp;
        int n = nums.size();
        long long ans = 1e9;
        for(int i = 0; i<n; i++) {
            if(mpp.find(nums[i]) != mpp.end()) {
                ans = min(ans,i-mpp[nums[i]]);
            }
            long long rev = reverse(nums[i]);
            mpp[rev] = max(i*1ll,mpp[rev]);
        }
        if(ans >= 1e9) return -1;
        return ans;
    }
};