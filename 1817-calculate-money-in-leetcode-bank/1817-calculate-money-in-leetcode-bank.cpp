class Solution {
public:
    int totalMoney(int n) {
        int cnt = n/7;
        int rem = n%7;
        int ans = (cnt+3)*(cnt+4)>>1;
        ans -= 3*4>>1;
        ans *= 7;
        for(int i = 1; i<=rem; i++) {
            ans += i+cnt;
        }
        return ans;
    }
};