class Solution {
public:
    long long hcf(long long a,long long b) {
        if(a == 0) return b;
        if(b == 0) return a;
        if(a > b) return hcf(a%b,b);
        return hcf(a,b%a);
    }
    bool check(vector<int> &d,vector<int> &r,long long &lcm,long long &mid) {
        long long d0 = mid-mid/r[0];
        long long d1 = mid-mid/r[1];
        long long total = mid-mid/lcm;
        if(d0 < d[0] || d1 < d[1]) return false;
        return total >= 1ll*d[0]+d[1];
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long h = hcf(r[0],r[1]);
        long long lcm = (1ll*r[0]*r[1])/h;
        long long l = 0,r1 = 1e18;
        long long ans = 0;
        while(l<=r1) {
            long long mid = (l+r1)>>1ll;
            if(check(d,r,lcm,mid)) {
                ans = mid;
                r1 = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};