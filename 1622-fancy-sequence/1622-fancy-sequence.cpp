class Fancy {
public:
    int mod = 1e9+7;
    long long add = 0,mul = 1;
    vector<long long> arr;
    Fancy() {
        
    }
    long long findP(long long a,long long b) {
        if(a == 0) return 0;
        if(b == 1) return a;
        if(b == 0) return 1ll;
        long long ans = findP(a,b>>1ll);
        if(b&1ll) return (((ans*ans)%mod)*a)%mod;
        return (ans*ans)%mod;
    }
    long long inv(long long n) {
        return findP(n,mod-2);
    }
    void append(int val) {
        long long temp = (val-add+mod)%mod;
        long long el = (temp*inv(mul))%mod;
        arr.push_back(el);
    }
    
    void addAll(int inc) {
        add += inc;
        add %= mod;
    }
    
    void multAll(int m) {
        mul *= m;
        mul %= mod;
        add = (add*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        return (arr[idx]*mul+add)%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */