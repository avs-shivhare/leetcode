class Solution {
public:
    bool hasAlternatingBits(int n) {
        for(int i = 1; i<32; i++) {
            if((1ll<<i) > n) break;
            int f = (n&(1<<i)) ? 1: 0;
            int s = (n&(1<<(i-1))) ? 1: 0;
            if(f == s) return false;
        }
        return true;
    }
};