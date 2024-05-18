class ST {
    public: 
    vector<int> s;
    int n = 0;
    ST(int size) {
        s.resize(size*4+1);
        n= size*4+1;
    }
    void build(vector<int> &arr,int node,int left,int right) {
        if(left >= right) {
            s[node] = arr[left];
            return;
        }
        int mid = (left+right)/2;
        build(arr,node*2+1,left,mid);
        build(arr,node*2+2,mid+1,right);
        s[node] = s[2*node+1]+s[2*node+2];
        return;
    }
    void update(int node,int left,int right,int idx,int val) {
        if(left >= right ) {
            if(left == idx) s[node] = val;
            return;
        }
        if(left > idx || right < idx) return;
        int mid = (left+right)/2;
        if(left <= idx && idx <= mid) update(node*2+1,left,mid,idx,val);
        else update(2*node+2,mid+1,right,idx,val);
        s[node] = s[node*2+1]+s[node*2+2];
        return; 
    }
    int query(int node,int left,int right,int l,int r) {
        if(r < left || l > right) return 0;
        if(l <= left && right <= r) return s[node];
        int mid = (left+right)/2;
        return query(node*2+1,left,mid,l,r)+query(node*2+2,mid+1,right,l,r);
    }
};
class NumArray {
public:
    ST s;
    int n = 0;
    NumArray(vector<int>& nums): s(nums.size()) {
        n = nums.size();
        //s(n);
        s.build(nums,0,0,n-1);
    }
    
    void update(int index, int val) {
        s.update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return s.query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */