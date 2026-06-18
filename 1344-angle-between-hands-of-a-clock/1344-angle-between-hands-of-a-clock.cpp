class Solution {
public:
    double angleClock(int h, int m) {
        h %= 12;
        double ans = abs(m*6-h*30-0.5*m);
        return min(ans,360-ans);
    }
};