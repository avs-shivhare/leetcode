class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = clamp(xCenter,x1,x2)-xCenter;
        int y = clamp(yCenter,y1,y2)-yCenter;
        return 1ll*x*x+y*y <= 1ll*radius*radius;
    }
};