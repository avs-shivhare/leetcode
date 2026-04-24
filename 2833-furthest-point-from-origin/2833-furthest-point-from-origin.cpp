class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0,r = 0;
        for(auto &i: moves) {
            if(i == 'L') {
                l++;
                r--;
            }
            else if(i == 'R') {
                r++;
                l--;
            }
            else {
                l++;
                r++;
            }
        }
        return max(l,r);
    }
};