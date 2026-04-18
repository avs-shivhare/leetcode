class Solution {
public:
    long long reverse(long long n) {
        long long rev = 0;
        while(n) {
            rev = rev*10+(n%10ll);
            n /= 10ll;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        return abs(1ll*n-reverse(n));
    }
};