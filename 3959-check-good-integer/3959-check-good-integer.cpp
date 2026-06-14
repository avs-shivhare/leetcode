class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum = 0,sq = 0;
        while(n) {
            int digit = n%10;
            sum += digit;
            sq += digit*digit;
            n /= 10;
        }
        return sq-sum >= 50;
    }
};