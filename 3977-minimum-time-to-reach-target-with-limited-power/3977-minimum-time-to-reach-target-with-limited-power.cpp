class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int p, vector<int>& cost, int s, int t) {
        vector<pair<int,int>> adj[n];
        for(auto &i: edges) {
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<long long,pair<long long,long long>>,vector<pair<long long,pair<long long,long long>>>,greater<pair<long long,pair<long long,long long>>>> q;
        vector<vector<long long>> dist(n+1,vector<long long>(1001,(long long)1e18));
        dist[s][p] = 0;
        q.push({0,{s,p}});
        while(!q.empty()) {
            auto node = q.top().second.first;
            auto time = q.top().first;
            auto po = q.top().second.second;
            q.pop();
            if(dist[node][po] > time || cost[node] > po) continue;
            for(auto &i: adj[node]) {
                if(po >= cost[node] && dist[i.first][po-cost[node]] > time+i.second) {
                    dist[i.first][po-cost[node]] = time+i.second;
                    q.push({time+i.second,{i.first,po-cost[node]}});
                }
            } 
        }
        long long mini = 1e18;
        for(int i = 0; i<=1000; i++) {
            mini = min(mini,dist[t][i]);
        }
        long long maxi = -1e18;
        for(int i = 0; i<=1000; i++) {
            if(dist[t][i] == mini) maxi = max(maxi,1ll*i);
        }
        if(mini >= 1e18) return {-1,-1};
        return {mini,maxi};
    }
};