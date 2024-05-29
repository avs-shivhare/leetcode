class Solution {
public:
    int minimumOneBitOperations(int n) {
        int operation = 0;
        vector<long long> f(32,0);
        f[0] = 1;
        for(int i =1; i<32; i++) {
            f[i] = 2*f[i-1]+1;
        }
        bool sign = true;
        int ans = 0;
        for(int i =31; i>=0; i--) {
            if((1<<i)&n) {
                if(sign) ans += f[i];
                else ans -= f[i];
                sign = ! sign;
            }
        }
        return ans;
    }
};