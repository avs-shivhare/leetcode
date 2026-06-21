class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string s, int k) {
        vector<pair<int,int>> adj[n];
        for(auto &i: edges) {
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<vector<int>> dist(n,vector<int>(k+1,1e9));
        dist[0][1] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        q.push({0,0,1});
        while(!q.empty()) {
            int cost = q.top()[0];
            int node = q.top()[1];
            int cnt = q.top()[2];
            q.pop();
            if(dist[node][cnt] < cost) continue;
            for(auto &i: adj[node]) {
                int ncnt = cnt;
                if(s[i.first] == s[node]) ncnt++;
                else ncnt = 1;
                if(ncnt <= k && dist[i.first][ncnt] > cost+i.second) {
                    //cout<<i.first<<" "<<node<<" "<<ncnt<<endl;
                    dist[i.first][ncnt] = cost+i.second;
                    q.push({cost+i.second,i.first,ncnt});
                }
            }
        }
        int ans = 1e9;
        for(auto &i: dist[n-1]) {
            ans = min(ans,i);
        }
        if(ans >= 1e9) return -1;
        return ans;
    }
};