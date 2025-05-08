class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mat) {
        priority_queue<pair<int,pair<int,pair<int,int>>>,vector<pair<int,pair<int,pair<int,int>>>>,greater<pair<int,pair<int,pair<int,int>>>>> q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<long long>> dist(n,vector<long long>(m,1e18));
        int rowdiff[4] = {1,-1,0,0};
        int coldiff[4] = {0,0,1,-1};
        dist[0][0] = 0;
        q.push({0,{0,{0,0}}});
        while(!q.empty()) {
            int cost = q.top().first;
            int el = q.top().second.first;
            int r = q.top().second.second.first;
            int c = q.top().second.second.second;
            q.pop();
            for(int i = 0; i<4; i++) {
                int newrow = r+rowdiff[i];
                int newcol = c+coldiff[i];
                if(newrow >=0 && newrow < n && newcol >=0 && newcol < m) {
                    int newcost = max(cost,mat[newrow][newcol])+(el&1?2:1);
                    if(dist[newrow][newcol] > newcost) {
                        dist[newrow][newcol] = newcost;
                        q.push({newcost,{(el+1)%2,{newrow,newcol}}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};