class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n,0);
        long long maxi = 0;
        for(int i = 0; i<n; i++) {
            maxi = max(maxi,1ll*nums[i]);
            prefix[i] = gcd(nums[i]*1ll,maxi);
        }
        sort(prefix.begin(),prefix.end());
        long long sum = 0;
        int l = 0,r = n-1;
        while(l<r) {
            sum += gcd(prefix[l],prefix[r]);
            l++;
            r--;
        }
        return sum;
    }
};