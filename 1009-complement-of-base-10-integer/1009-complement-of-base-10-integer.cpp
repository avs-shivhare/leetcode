class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        long long ans = 0;
        int i = 0;
        while(n) {
            if((n&1) == 0) {
                ans |= (1<<i);
            }
            i++;
            n >>= 1;
        }
        return ans;
    }
};