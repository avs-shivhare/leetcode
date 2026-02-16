class Solution {
public:
    int reverseBits(int n) {
        long long ans = 0;
        for(int i = 0; i<32; i++) {
            int x = 32-i-1;
            if((1ll*n)&(1ll<<i)) ans |= 1ll<<x;
        }
        return ans;
    }
};