class Solution {
public:
    int minOperations(string s, int k) {
        long long n = s.size();
        long long zero = 0,one = 0;
        for(auto &i: s) {
            if(i == '0') zero++;
        }
        one = n-zero;
        if(one == n) return 0;
        for(long long i = 1; i<=n; i++) {
            long long total = i*k;
            if((total-zero)&1ll) continue;
            if(i&1) {
                if(total >= zero && total <= zero*i+one*(i-1)) return i;
            }
            else {
                if(total >= zero && total <= zero*(i-1)+one*i) return i;
            }
        }
        return -1;
    }
};