class Solution {
public:
    bool validDigit(int n, int x) {
        int last = 0;
        int cnt = 0;
        while(n) {
            last = n%10;
            n /= 10;
            if(last == x) cnt++;
        }
        if(last != x && cnt) return true;
        return false;
    }
};