class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string s, int k) {
        vector<pair<int,int>> adj[n];
        for(auto &i: edges) {
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<vector<int>> dist(n,vector<int>(k+1,1e9));
        dist[0][1] = 0;
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> q;
        q.push({0,1,0});
        while(!q.empty()) {
            int cost = q.top()[0];
            int cnt = q.top()[1];
            int node = q.top()[2];
            q.pop();
            if(dist[node][cnt] < cost) continue;
            for(auto &i: adj[node]) {
                int ncnt = cnt;
                if(s[i.first] == s[node]) ncnt++;
                else ncnt = 1;
                if(ncnt <= k && dist[i.first][ncnt] > cost+i.second) {
                    dist[i.first][ncnt] = cost+i.second;
                    q.push({cost+i.second,ncnt,i.first});
                }
            }
        }
        int ans = 1e9;
        for(int i = 0; i<=k; i++) ans = min(ans,dist[n-1][i]);
        if(ans >= 1e9) return -1;
        return ans;
    }
};