class Solution {
public:
    bool canAliceWin(int n) {
        bool flag = true;
        int last = 10;
        while(n && n >= last) {
            n -= last;
            last--;
            flag = !flag;
        }
        return !flag;
    }
};