class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int digit = 1;
        int x = n;
        while(x) {
            int d = x%10;
            x /= 10;
            sum += d;
            digit *= d;
        }
        return n%(sum+digit) == 0;
    }
};