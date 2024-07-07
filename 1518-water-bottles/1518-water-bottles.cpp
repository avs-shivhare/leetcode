class Solution {
public:
    int numWaterBottles(int n, int e) {
        int ans = n;
        while(n >= e) {
            int temp = n/e;
            n -= temp*e;
            ans += temp;
            n += temp;
        }
        return ans;
    }
};