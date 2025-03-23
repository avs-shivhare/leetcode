class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[201];
        for(auto i: roads) {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        vector<long long> dist(n,1e18);
        dist[0] = 0;
        q.push({0,0});
        vector<int> cnt(n,0);
        dist[0] = 0;
        cnt[0] = 1;
        int mod = 1e9+7;
        while(!q.empty()) {
            auto cost = q.top().first;
            auto node = q.top().second;
            q.pop();
            for(auto i: adj[node]) {
                if(dist[i.first] > cost+i.second) {
                    dist[i.first] = cost+i.second;
                    cnt[i.first] = cnt[node];
                    q.push({i.second+cost,i.first});
                }
                else if(dist[i.first] == cost+i.second) {
                    cnt[i.first] += cnt[node];
                    cnt[i.first] %= mod;
                }
            }
        }
        return cnt[n-1];
    }
};