class Solution {
public:
    vector<long long> h1,h2,p1,p2;
    long long mod1 = 1e9+7,mod2 = 1e9+9;
    long long base1 = 100003,base2 = 1000033;
    void build(vector<int> &nums) {
        int n = nums.size();
        h1.resize(n+1,0),h2.resize(n+1),p1.resize(n+1),p2.resize(n+1);
        p1[0] = p2[0] = 1;
        for(int i = 0; i<n; i++) {
            h1[i+1] = (h1[i]*base1+nums[i])%mod1;
            h2[i+1] = (h2[i]*base2+nums[i])%mod2;
            p1[i+1] = (base1*p1[i])%mod1;
            p2[i+1] = (base2*p2[i])%mod2;
        }
        return;
    }
    bool check(int mid) {
        map<pair<long long,long long>,int> mpp;
        int n = h1.size();
        for(int i = 0; i+mid<n; i++) {
            long long a = ((h1[i+mid]-h1[i]*p1[mid])%mod1+mod1)%mod1;
            long long b = ((h2[i+mid]-h2[i]*p2[mid])%mod2+mod2)%mod2;
            mpp[{a,b}]++;
        }
        for(auto &i: mpp) {
            if(i.second == 1) return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        build(nums);
        int l = 1,r = nums.size();
        int ans = r;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(check(mid)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};