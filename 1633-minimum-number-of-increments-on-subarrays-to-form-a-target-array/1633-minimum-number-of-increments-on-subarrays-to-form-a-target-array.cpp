class SegmentTree {
    public:
    vector<int> sg;
    SegmentTree(int n,vector<int> &arr) {
        sg.resize(4*n+1,0);
        build(0,n-1,0,arr);
    }
    void build(int l,int r,int ind,vector<int> &arr) {
        if(l == r) {
            sg[ind] = l;
            return;
        }
        int mid = (l+r)>>1;
        build(l,mid,2*ind+1,arr);
        build(mid+1,r,2*ind+2,arr);
        if(arr[sg[2*ind+1]] < arr[sg[2*ind+2]]) sg[ind] = sg[2*ind+1];
        else sg[ind] = sg[2*ind+2];
        return;
    }
    int query(int l,int r,int ind,int ql,int qr,vector<int> &arr) {
        if(l > qr || r < ql) return -1;
        if(ql <= l && r <= qr) return sg[ind];
        int mid = (l+r)>>1;
        int left = query(l,mid,2*ind+1,ql,qr,arr);
        int right = query(mid+1,r,2*ind+2,ql,qr,arr);
        if(left != -1 && right != -1) {
            return (arr[left] < arr[right] ? left: right);
        }
        else if(left == -1) return right;
        return left;
    }
};

class Solution {
public:
    int find(int l,int r,int curr,vector<int> &arr,SegmentTree &s) {
        if(l > r) return 0;
        //cout<<l<<" "<<r<<endl;
        if(l == r) {
            return arr[l]-curr;
        }
        int ind = s.query(0,arr.size()-1,0,l,r,arr);
        // cout<<ind<<endl;
        // if(ind == -1) ind = l;
        int ans = arr[ind]-curr+find(l,ind-1,arr[ind],arr,s);
        ans += find(ind+1,r,arr[ind],arr,s);
        return ans;
    }
    int minNumberOperations(vector<int>& target) {
        SegmentTree s(target.size(),target);
        return find(0,target.size()-1,0,target,s);
    }
};