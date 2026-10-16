int mod = 1e9+7;
class SGL {
    public:
    vector<long long> cnt,sq,lazy;
    SGL(int n) {
        cnt.resize(4*n+1,0);
        sq.resize(4*n+1,0);
        lazy.resize(4*n+1,0);
    }
    void find(int i,int l,int r) {
        if(lazy[i] == 0 || l > r) return;
        long long x = lazy[i];
        long long len = r-l+1;
        sq[i] = (sq[i]+((2ll*x*cnt[i])%mod)+((len*x*x)%mod))%mod;
        cnt[i] = (cnt[i]+(len*x))%mod;
        if(l != r) {
            lazy[2*i+1] += x;
            lazy[2*i+2] += x;
        }
        lazy[i] = 0;
        return;
    }
    void update(int l,int r,int ind,int ql,int qr,int x) {
        find(ind,l,r);
        if(r < ql || l > qr) return;
        if(ql <= l && r <= qr) {
            lazy[ind] += x;
            find(ind,l,r);
            return;
        }
        int mid = (l+r)>>1;
        update(l,mid,2*ind+1,ql,qr,x);
        update(mid+1,r,2*ind+2,ql,qr,x);
        cnt[ind] = (cnt[2*ind+1]+cnt[2*ind+2])%mod;
        sq[ind] = (sq[2*ind+1]+sq[2*ind+2])%mod;
        return;
    }
    int query(int l,int r,int ind,int ql,int qr) {
        if(r < ql || l > qr) return 0;
        if(ql <= l && qr <= r) {
            find(ind,l,r);
            return sq[ind];
        }
        int mid = (l+r)>>1;
        return (query(l,mid,2*ind+1,ql,qr)+query(mid+1,r,2*ind+2,ql,qr))%mod;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SGL sg(n);
        int ans = 0;
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++) {
            int last = 0;
            if(mpp.find(nums[i]) != mpp.end()) last = mpp[nums[i]]+1;
            sg.update(0,n-1,0,last,i,1);
            mpp[nums[i]] = i;
            ans = (ans+sg.query(0,n-1,0,0,n-1))%mod;
        }
        return ans;
    }
};