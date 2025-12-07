class Solution {
public:
    int countOdds(int low, int high) {
        if((low&1ll) || (high&1ll)) {
            return ((1ll*high-1ll*low)>>1)+1;
        }
        return (1ll*high-1ll*low)>>1;
    }
};