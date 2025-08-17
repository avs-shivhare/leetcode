class Solution {
public:
    int minSensors(int n, int m, int k) {
        int r = 0,c = 0;
        int cnt = 0;
        while(true) {
            r += k;
            c = 0;
            while(true) {
                c += k;
                cnt++;
                c += k+1;
                if(c >= m) break;
            }
            r += k+1;
            if(r >= n) break;
        }
        return cnt;
    }
};