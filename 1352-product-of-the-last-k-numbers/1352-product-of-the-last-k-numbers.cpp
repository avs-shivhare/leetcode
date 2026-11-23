class SG {
    public:
    vector<long long> sg;
    SG(int n) {
        sg.resize(4*n+1,1);
    }
    void update(int l,int r,int ind,int &index,int &val) {
        if(l == r) {
            if(l == index) {
                sg[ind] = val;
            }
            return;
        }
        int mid = (l+r)>>1;
        if(mid < index) update(mid+1,r,2*ind+2,index,val);
        else update(l,mid,2*ind+1,index,val);
        sg[ind] = sg[2*ind+1]*sg[2*ind+2];
        return;
    }
    long long query(int l,int r,int ql,int qr,int ind) {
        if(r < ql || qr < l) return 1ll;
        if(ql <= l && r <= qr) return sg[ind];
        int mid = (l+r)>>1;
        return query(l,mid,ql,qr,2*ind+1)*query(mid+1,r,ql,qr,2*ind+2);
    }
};

class ProductOfNumbers {
public:
    SG *s;
    int ind = 0;
    ProductOfNumbers() {
        s = new SG(100001);
    }
    
    void add(int num) {
        s->update(0,100000,0,ind,num);
        ind++;
    }
    
    int getProduct(int k) {
        return s->query(0,100000,ind-k,ind-1,0);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */