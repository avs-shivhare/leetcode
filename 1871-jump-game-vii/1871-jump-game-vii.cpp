class SG {
    public:
    vector<int> sg;
    SG(int n) {
        sg.resize(4*n+1,0);
    }
    void update(int l,int r,int ind,int val,int index) {
        if(l > r || l > index || r < index) return;
        if(l == r) {
            if(index == l) {
                sg[ind] = val;
            }
            return;
        }
        int mid = (l+r)>>1;
        update(l,mid,2*ind+1,val,index);
        update(mid+1,r,2*ind+2,val,index);
        sg[ind] = sg[2*ind+1]+sg[2*ind+2];
        return;
    }
    int query(int l,int r,int ql,int qr,int ind) {
        if(l > r || ql > r || qr < l) return 0;
        if(ql <= l && r <= qr) return sg[ind];
        int mid = (l+r)>>1;
        if(query(l,mid,ql,qr,2*ind+1)) return 1;
        return query(mid+1,r,ql,qr,2*ind+2);
    }
};
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        SG sg(n);
        if(s[n-1] == '0') sg.update(0,n-1,0,1,n-1);
        for(int i = n-2; i>=0; i--) {
            if(s[i] == '1') continue;
            int temp = sg.query(0,n-1,i+minJump,i+maxJump,0);
            if(temp) sg.update(0,n-1,0,1,i); 
        }
        return sg.query(0,n-1,0,0,0);
    }
};