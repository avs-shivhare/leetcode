class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0;
        int cnt2 = 0;
        while(n) {
            if(n&1) cnt++;
            else cnt = 0;
            n >>=1;
            if(cnt >= 2) cnt2++; 
        }
        return cnt2 == 1;
    }
};