class SG {
    public:
    int n;
    vector<long long> sg;
    SG(int x) {
        n = x;
        sg.resize(4*n+1,0);
    }
    void Build(vector<int> &nums) {
        build(0,n-1,0,nums);
    }
    void build(int l,int r,int ind,vector<int> &nums) {
        if(l == r) {
            sg[ind] = nums[l];
            return;
        }
        int mid = (l+r)>>1;
        build(l,mid,2*ind+1,nums);
        build(mid+1,r,2*ind+2,nums);
        sg[ind] = max(sg[2*ind+1],sg[2*ind+2]);
        return;
    }
    long long Query(int l,int r) {
        return query(0,n-1,l,r,0);
    }
    long long query(int l,int r,int ql,int qr,int ind) {
        if(l > r || ql > r || qr < l) return -1e18;
        if(ql <= l && r <= qr) return sg[ind];
        int mid = (l+r)>>1;
        return max(query(l,mid,ql,qr,2*ind+1),query(mid+1,r,ql,qr,2*ind+2));
    }
};

class SG2 {
    public:
    int n;
    vector<long long> sg;
    SG2(int x) {
        n = x;
        sg.resize(4*n+1,0);
    }
    void Build(vector<int> &nums) {
        build(0,n-1,0,nums);
    }
    void build(int l,int r,int ind,vector<int> &nums) {
        if(l == r) {
            sg[ind] = nums[l];
            return;
        }
        int mid = (l+r)>>1;
        build(l,mid,2*ind+1,nums);
        build(mid+1,r,2*ind+2,nums);
        sg[ind] = min(sg[2*ind+1],sg[2*ind+2]);
        return;
    }
    long long Query(int l,int r) {
        return query(0,n-1,l,r,0);
    }
    long long query(int l,int r,int ql,int qr,int ind) {
        if(l > r || ql > r || qr < l) return 1e18;
        if(ql <= l && r <= qr) return sg[ind];
        int mid = (l+r)>>1;
        return min(query(l,mid,ql,qr,2*ind+1),query(mid+1,r,ql,qr,2*ind+2));
    }
};
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<vector<long long>> q;
        SG maxi(n);
        SG2 mini(n);
        maxi.Build(nums);
        mini.Build(nums);
        long long sum = 0;
        q.push({maxi.Query(0,n-1)-mini.Query(0,n-1),0,n-1});
        set<pair<int,int>> st;
        st.insert({0,n-1});
        while(!q.empty() && k--) {
            long long sum2 = q.top()[0];
            int l = q.top()[1];
            int r = q.top()[2];
            q.pop();
            sum += sum2;
            if(l+1 <= r && st.find({l+1,r}) == st.end()) {
                q.push({maxi.Query(l+1,r)-mini.Query(l+1,r),l+1,r});
                st.insert({l+1,r});
            }
            if(l <= r-1 && st.find({l,r-1}) == st.end()) {
                q.push({maxi.Query(l,r-1)-mini.Query(l,r-1),l,r-1});
                st.insert({l,r-1});
            }
        }
        return sum;
    }
};