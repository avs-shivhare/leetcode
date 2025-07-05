class Solution {
public:
    long long minCost(int n, int m, vector<vector<int>>& w) {
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> q;
        vector<vector<vector<long long>>> dist(n,vector<vector<long long>>(m,vector<long long>(2,1e18)));
        q.push({1,0,0,1});
        dist[0][0][1] = 1;
        int rowdiff[2] = {0,1};
        int coldiff[2] = {1,0};
        while(!q.empty()) {
            long long cost = q.top()[0];
            int r = q.top()[1];
            int c = q.top()[2];
            int s = q.top()[3];
            q.pop();
            //cout<<r<<" "<<c<<" "<<cost<<" "<<s<<endl;
            if(s) {
                for(int i = 0; i<2; i++) {
                    int newr = r+rowdiff[i];
                    int newc = c+coldiff[i];
                    if(newr >= 0 && newr < n && newc >= 0 && newc < m) {
                        if(dist[newr][newc][(s+1)%2] > cost+(newr+1)*(newc+1)) {
                            dist[newr][newc][(s+1)%2] = cost+(newr+1)*(newc+1);
                            q.push({cost+(newr+1)*(newc+1),newr,newc,(s+1)%2});
                        }
                    }
                }
            }
            else {
                if(dist[r][c][(s+1)%2] > cost+w[r][c]) {
                    dist[r][c][(s+1)%2] = cost+w[r][c];
                    q.push({cost+w[r][c],r,c,(s+1)%2});
                }
            }
        }
        return min(dist[n-1][m-1][0],dist[n-1][m-1][1]);
    }
};