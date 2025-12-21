class Solution {
public:
    long long find(long long n) {
        long long rev = 0;
        while(n) {
            rev = rev*10+n%10;
            n /=10;
        }
        return rev;
    } 
    int mirrorDistance(int n) {
        long long rev = find(n);
        return llabs(rev-1ll*n);
    }
};