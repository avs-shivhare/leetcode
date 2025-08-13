class Solution {
public:
    bool find(long long n) {
        if(n == 1) return true;
        if(n <= 0) return false;
        if(n%3 != 0) return false;
        return find(n/3);
    }
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        return find(n);
    }
};