class Solution {
public:
    int numberOfWays(string c) {
        long long ans = 1;
        int mod = 1e9+7;
        int n = c.size();
        int s = 0,p = 0;
        int total =0;
        int j = 0;
        while(j<n && c[j] == 'P') j++;
        for(int i = n-1; i>=j; i--) {
            if(c[i] == 'S') {
                if(s == 2) {
                    ans *= 1ll*(p+1);
                    p = 0;
                    s = 0;
                }
                p = 0;
                s++;
                total++;
            }
            else p++;
            ans %= mod;
        }
        if(s == 2) {
            ans *= 1ll*(p+1);
            p = 0;
            s = 1;
        }
        if((total&1ll) || j == n) return 0;
        return ans;
    }
};