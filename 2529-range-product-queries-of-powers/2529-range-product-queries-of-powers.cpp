int mod = 1e9+7;
class SG{
    public:
    vector<long long> sg;
    SG(int n,vector<int> &p) {
        sg.resize(4*n+1,0);
        build(0,n-1,0,p);
    }
    void build(int l,int r,int ind,vector<int> &p) {
        if(l == r) {
            sg[ind] = p[l];
            return;
        }
        int mid = (l+r)>>1;
        build(l,mid,2*ind+1,p);
        build(mid+1,r,2*ind+2,p);
        sg[ind] = (sg[2*ind+1]*sg[2*ind+2])%mod;
        return;
    }
    long long query(int ql,int qr,int l,int r,int ind) {
        if(l > r || ql > r || qr < l) return 1;
        if(ql <= l && r <= qr) return sg[ind];
        int mid = (l+r)>>1;
        return (query(ql,qr,l,mid,2*ind+1)*query(ql,qr,mid+1,r,2*ind+2))%mod;
    }
};
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        for(int i = 0; i<32; i++) {
            if(n & (1<<i)) power.push_back(1<<i);
        }
        SG s(power.size(),power);
        n = power.size();
        vector<int> ans;
        for(auto i: queries) {
            ans.push_back(s.query(i[0],i[1],0,n-1,0));
        }
        return ans;
    }
};