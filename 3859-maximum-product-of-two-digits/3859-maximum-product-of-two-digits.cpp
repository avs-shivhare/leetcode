class Solution {
public:
    int maxProduct(int n) {
        int digit = 0,digit2 = 0;
        while(n) {
            int x = n%10;
            n /= 10;
            if(digit < x) {
                digit2 = digit;
                digit = x;
            }
            else if(digit2 < x) {
                digit2 = x;
            }
        }
        return digit*digit2;
    }
};