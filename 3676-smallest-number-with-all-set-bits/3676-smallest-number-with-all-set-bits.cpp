class Solution {
public:
    int smallestNumber(int n) {
        int cnt = 0;
        while(n) {
            cnt++;
            n >>= 1;
        }
        int ans = 1<<cnt;
        return ans-1;
    }
};