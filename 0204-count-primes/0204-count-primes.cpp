class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int cnt =0;
        vector<int> vis(n+1,true);
        for(int i =2; i*i<=n; i++) {
            for(int j = i*i;j<=n; j+=i) {
                vis[j] = false;
            }
        }
        for(int i =2; i<n; i++) {
            if(vis[i]) cnt++;
        }
        return cnt;
    }
};