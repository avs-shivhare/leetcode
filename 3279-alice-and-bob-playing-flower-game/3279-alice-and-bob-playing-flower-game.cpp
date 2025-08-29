class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;
        int even = n/2;
        int odd = (n+1)/2;
        for(int i = 1; i<=m; i++) {
            int x = i%2;
            ans += (x == 0? odd: even);
        }
        return ans;
    }
};