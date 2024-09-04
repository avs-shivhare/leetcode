class Solution {
public:
    int dir = 0;
    int rowdiff[4] = {0,1,0,-1};
    int coldiff[4] = {1,0,-1,0};

    int robotSim(vector<int>& cmd, vector<vector<int>>& obs) {
        set<pair<int,int>> st;
        for(auto i: obs) {
            st.insert({i[0],i[1]});
        }
        int maxi = 0;
        int x = 0,y =0;
        for(auto i: cmd) {
            if(i == -2){
                dir--;
                if(dir == -1) dir = 3;
            }
            else if(i == -1) dir = (dir+1)%4;
            else {
                for(int j = 0; j<i; j++) {
                    int newx = x+rowdiff[dir];
                    int newy = y+coldiff[dir];
                    if(st.count({newx,newy}) == 0) {
                        x = newx;
                        y = newy;
                    }
                    else break;
                }
            }
            maxi = max(maxi,(x*x)+(y*y));
        }
        return maxi;
    }
};