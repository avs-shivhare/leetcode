class Solution {
public:
    int concatenatedBinary(int n) {
        long long mod = 1e9+7;
        long long ans = 0;
        for(long long i = 1; i<=n; i++) {
            bool flag = false;
            for(int j = 17; j>=0; j--) {
                if(i&(1<<j)) {
                    //cout<<j<<endl;
                    flag = true;
                }
                if(flag) {
                    if(i&(1<<j)) {
                        ans <<= 1ll;
                        ans |= 1ll;
                        ans %= mod;
                    }
                    else {
                        ans <<= 1ll;
                        ans %= mod;
                    }
                }
            }
            //cout<<ans<<" "<<i<<endl;
        }
        return ans;
    }
};