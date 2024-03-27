class Solution {
public:
    double myPow(double x, int n) {
        long long dup = n;
        if(dup<0) dup *= -1;
        double ans = 1;
        while(dup>0) {
            if(dup%2 == 1) {
                ans = ans *x;
                dup--;
            }
            else {
                x = x*x;
                dup /=2;
            }
        }
        if(n <0) return 1/ans;
        return ans;
    }
};