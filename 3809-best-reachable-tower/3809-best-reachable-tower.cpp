class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& c, int r) {
        int qf = -1;
        vector<int> ans(2,-1);
        for(auto &i: towers) {
            int dist = abs(c[0]-i[0])+abs(c[1]-i[1]);
            if(dist <= r) {
                if(qf < i[2]) {
                    ans = {i[0],i[1]};
                    qf = i[2];
                }
                else if(qf == i[2]) ans = min(ans,{i[0],i[1]});
            }
        }
        return ans;
    }
};