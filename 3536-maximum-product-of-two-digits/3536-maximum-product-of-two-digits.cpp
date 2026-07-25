class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0,maxi2 = 0;
        while(n) {
            int digit = n%10;
            if(maxi < digit) {
                maxi2 = maxi;
                maxi = digit;
            }
            else if(maxi2 < digit) maxi2 = digit;
            n /= 10;
        }
        return maxi*maxi2;
    }
};