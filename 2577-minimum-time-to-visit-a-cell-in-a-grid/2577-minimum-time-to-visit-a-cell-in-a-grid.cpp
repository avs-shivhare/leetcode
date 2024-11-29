class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        int row[4] = {1,-1,0,0};
        int col[4] = {0,0,1,-1};
        while(!q.empty()) {
            int cost = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            bool flag = false;
            for(int i =0; i<4; i++) {
                int newrow = r+row[i];
                int newcol = c+col[i];
                if(newrow >=0 && newrow < n && newcol >=0 && newcol < m) {
                    if(grid[newrow][newcol] <= cost+1 && dist[newrow][newcol] > cost+1) {
                        dist[newrow][newcol] = cost+1;
                        q.push({cost+1,{newrow,newcol}});
                        flag = true;
                    }
                    else if(dist[newrow][newcol] <= cost+1) {
                        flag = true;
                    }
                }
            }
            if(flag) {
                for(int i =0; i<4; i++) {
                    int newrow = r+row[i];
                    int newcol = c+col[i];
                    if(newrow >=0 && newrow < n && newcol >=0 && newcol < m) {
                        if(cost+1 < grid[newrow][newcol]) {
                            int t = grid[newrow][newcol]-(cost+1);
                            int x = t/2+(t&1 == 1? 1:0);
                            x *=2;
                            if(dist[newrow][newcol] > cost+1+x) {
                                //cout<<cost+1+x<<" "<<newrow<<" "<<newcol<<" "<<r<<" "<<c<<endl;
                                dist[newrow][newcol] = cost+1+x;
                                q.push({cost+1+x,{newrow,newcol}});
                            }
                        }
                    }
                }
            }
        }
        if(dist[n-1][m-1] >= 1e9) return -1;
        return dist[n-1][m-1];
    }
};