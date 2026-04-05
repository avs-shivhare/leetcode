class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0,y = 0;
        for(auto &i: moves) {
            if(i == 'L') x--;
            else if(i == 'R') x++;
            else if(i == 'U') y++;
            else y--;
        }
        return x == 0 && y == 0;
    }
};