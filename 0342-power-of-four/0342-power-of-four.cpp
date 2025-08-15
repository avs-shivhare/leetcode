class Solution {
public:
    bool find(long long n) {
        if(n == 1) return true;
        if(n <= 0) return false;
        if(n%4 != 0) return false;
        return find(n/4);
    }
    bool isPowerOfFour(int n) {
        return find(n);
    }
};