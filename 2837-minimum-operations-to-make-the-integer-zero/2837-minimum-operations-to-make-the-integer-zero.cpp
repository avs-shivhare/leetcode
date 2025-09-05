class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i = 1; i<=60; i++) {
            long long a = num1-1ll*num2*i;
            if(a < i) return -1;
            int cnt = 0;
            for(int j = 0; j<64; j++) {
                if(a & (1ll<<j)) cnt++;
            }
            if(i >= cnt) return i;
        }
        return -1;
    }
};