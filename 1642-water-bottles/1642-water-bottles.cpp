class Solution {
public:
    int numWaterBottles(int n, int ex) {
        int empty = 0;
        int ans = 0;
        while(n) {
            ans += n;
            empty += n;
            n = empty/ex;
            empty %= ex;
            //cout<<empty<<endl;
        }
        return ans;
    }
};