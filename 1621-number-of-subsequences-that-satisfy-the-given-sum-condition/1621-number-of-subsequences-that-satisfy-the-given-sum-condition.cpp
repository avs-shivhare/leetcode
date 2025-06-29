class Solution {
public:
    int mod = 1e9+7;
    long long power(long long x,long long n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(x == 0) return 0;
        long long ans = power(x,n/2);
        if(n&1) {
            return (((ans*ans)%mod)*x)%mod;
        }
        return (ans*ans)%mod;
    }
    int find(vector<int> &arr,int l,int r,int &target,int x) {
        int ans = -1;
        while(l<=r) {
            int mid= (l+r)>>1;
            if(x+arr[mid] <= target) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long cnt = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            int last = find(nums,i,n-1,target,nums[i]);
            if(last == -1) continue;
            int len = last-i+1;
            cnt += power(2,len-1);
            cnt %= mod;
        }
        return cnt;
    }
};