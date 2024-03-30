class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag = true;
        if((dividend <0 && divisor >=0) || (dividend >= 0 && divisor <0)) flag = false;
        long long d = abs(divisor);
        long long n = abs(dividend);
        long long ans = 0;
        while(n>= d) {
            int cnt =0;
            while(n >= (d<<(cnt+1))) {
                cnt++;
            }
            ans += (1<<cnt);
            n -= (d<<cnt);
        }
        if(ans == (1<<31) && flag) return INT_MAX;
        if(ans == (1<<31) && !flag) return INT_MIN;
        return flag? ans:(-ans);
    }
};