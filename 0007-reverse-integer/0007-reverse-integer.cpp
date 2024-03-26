class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        long long dup = x;
        if(x <0) {
            dup *= -1;
            neg = true;
        }
        long long ans = 0;
        while(dup) {
            ans = ans*10 + dup%10;
            dup /= 10;
        }
        if(neg) {
            ans *= -1;
        }
        if(ans < -2147483648 || ans > 2147483647) return 0;
        return ans;
    }
};