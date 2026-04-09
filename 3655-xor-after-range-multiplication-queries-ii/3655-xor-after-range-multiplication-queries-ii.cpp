class Solution {
public:
    int mod = 1e9+7;
    long long power(long long a,long long b) {
        if(a == 0) return 0;
        if(b == 0) return 1ll;
        if(b == 1) return a;
        long long ans = power(a,b>>1ll);
        if(b&1ll) return (((ans*ans)%mod)*a)%mod;
        return (ans*ans)%mod;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sq = sqrt(n);
        unordered_map<int,vector<vector<int>>> mpp;
        for(auto &i: queries) {
            long long l = i[0], r = i[1], k = i[2], v = i[3];
            if(k >= sq) {
                for(int j = l; j<n && j<=r; j+=k) {
                    nums[j] = (1ll*nums[j]*v)%mod;
                }
            }
            else{
                mpp[k].push_back(i);
            }
        }
        for(auto &i: mpp) {
            vector<long long> diff(n,1ll);
            for(auto &j: i.second) {
                long long l = j[0], r = j[1], k = j[2], v = j[3];
                diff[l] = (diff[l]*v)%mod;
                int step = (r-l)/k;
                int next = l+(step+1)*k;
                long long iv = power(v,mod-2);
                if(next < n) diff[next] = (diff[next]*iv)%mod;
            }
            for(int j = 0; j<n; j++) {
                if(j>=i.first) diff[j] = (diff[j]*diff[j-i.first])%mod;
                nums[j] = (1ll*nums[j]*diff[j])%mod;
            }
        }
        long long ans = 0;
        for(auto &i: nums) {
            ans ^= i;
        }
        return ans;
    }
};