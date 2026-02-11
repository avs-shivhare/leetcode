class SG {
    public:
    vector<int> maxi,mini,lazy;
    SG(int n) {
        maxi.resize(4*n+1);
        mini.resize(4*n+1);
        lazy.resize(4*n+1);
    }
    void push(int l,int r,int ind) {
        if(lazy[ind] == 0) return;
        mini[ind] += lazy[ind];
        maxi[ind] += lazy[ind];
        if(l<r) {
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
        return;
    }
    void update(int l,int r,int ind,int ql,int qr,int val) {
        push(l,r,ind);
        if(qr < l || ql > r) return;
        if(ql <= l && r <= qr) {
            lazy[ind] += val;
            push(l,r,ind);
            return;
        }
        int mid = (l+r)>>1;
        update(l,mid,2*ind+1,ql,qr,val);
        update(mid+1,r,2*ind+2,ql,qr,val);
        mini[ind] = min(mini[2*ind+1],mini[2*ind+2]);
        maxi[ind] = max(maxi[2*ind+1],maxi[2*ind+2]);
        return;
    }
    int query(int l,int r,int ind,int ql,int qr) {
        if(l > r) return -1;
        push(l,r,ind);
        if(ql > r || qr < l || mini[ind] > 0 || maxi[ind] < 0) return -1;
        if(l == r) {
            if(mini[ind] == 0) return l;
            return -1;
        }
        int mid = (l+r)>>1;
        int left = query(l,mid,2*ind+1,ql,qr);
        if(left != -1) return left;
        return query(mid+1,r,2*ind+2,ql,qr);
    }
};
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SG s(n);
        unordered_map<int,int> mpp;
        int ans = 0;
        for(int i = 0; i<n; i++) {
            int val = 0;
            if(nums[i]&1) val++;
            else val--;
            if(mpp.find(nums[i]) != mpp.end()) s.update(0,n-1,0,mpp[nums[i]]+1,i,val);
            else s.update(0,n-1,0,0,i,val);
            mpp[nums[i]] = i;
            int j = s.query(0,n-1,0,0,i);
            if(j != -1) ans = max(ans,i-j+1);
        }
        return ans;
    }
};