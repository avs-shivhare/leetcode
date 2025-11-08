class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<long long> prefix(32,0);
        prefix[0] = 1;
        for(int i = 1; i<32; i++) {
            prefix[i] = 2*prefix[i-1]+1;
        }
        long long ans = 0;
        int cnt = 1;
        for(int i = 31; i>=0; i--) {
            if((1<<i)&n) {
                if(cnt) ans += prefix[i];
                else ans -= prefix[i];
                cnt ^= 1;
            }
        }
        return ans;
    }
};