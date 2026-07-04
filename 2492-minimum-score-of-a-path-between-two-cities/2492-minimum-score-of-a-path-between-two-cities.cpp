class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1];
        for(auto &i: roads) {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> dist(n+1,1e9);
        q.push({1e9,1});
        while(!q.empty()) {
            int cost = q.top().first;
            int node = q.top().second;
            q.pop();
            if(dist[node] < cost) continue;
            for(auto &i: adj[node]) {
                if(dist[i.first] > min(cost,i.second)) {
                    dist[i.first] = min(cost,i.second);
                    q.push({dist[i.first],i.first});
                }
            }
        }
        return dist[n];
    }
};