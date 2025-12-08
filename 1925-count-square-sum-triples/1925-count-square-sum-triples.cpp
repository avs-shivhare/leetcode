class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=n; j++) {
                for(int k = 1; k<=n; k++) {
                    if(1ll*i*i+1ll*j*j == 1ll*k*k) cnt++;
                }
            }
        }
        return cnt;
    }
};