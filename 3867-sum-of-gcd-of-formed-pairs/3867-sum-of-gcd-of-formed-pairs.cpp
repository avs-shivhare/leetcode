class Solution {
public:
    long long find(long long a,long long b) {
        if(a == 0) return b;
        if(b == 0) return a;
        if(a > b) return find(a%b,b);
        return find(a,b%a);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n,0);
        long long maxi = -1e18;
        for(int i = 0; i<n; i++) {
            maxi = max(1ll*nums[i],maxi);
            prefix[i] = find(nums[i],maxi);
        }
        sort(prefix.begin(),prefix.end());
        int l = 0,r = n-1;
        long long ans = 0;
        while(l<r) {
            ans += find(prefix[l],prefix[r]);
            l++;
            r--;
        }
        return ans;
    }
};