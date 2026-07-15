class Solution {
public:
    long long find(long long a,long long b) {
        if(a == 0) return b;
        if(b == 0) return a;
        if(a > b) return find(a%b,b);
        return find(a,b%a);
    }
    int gcdOfOddEvenSums(int n) {
        long long total = (2ll*n*(2ll*n+1)>>1ll);
        long long even = 2ll*((n+(n+1))>>1ll);
        long long odd = total-even;
        return find(odd,even);
    }
};