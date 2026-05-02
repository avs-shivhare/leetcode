class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1; i<=n; i++) {
            bool flag = false;
            long long t = i;
            while(t) {
                long long digit = t%10;
                if(digit == 3 || digit == 4 || digit == 7) {
                    flag = false;
                    break;
                }
                else if(digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    flag = true;
                }
                t /= 10ll;
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};