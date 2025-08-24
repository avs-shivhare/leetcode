class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long total = 2ll*n;
        total = total*(total+1)/2;
        long long even = 2ll*((long long)n*(n+1)/2);
        long long odd = total-even;
        return gcd(even,odd);
    }
};