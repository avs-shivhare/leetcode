class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& con) {
        int n = con.size()+1;
        vector<pair<int,long long>> adj[100001];
        for(auto i: con) {
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,long long>,vector<pair<int,long long>>,greater<pair<int,long long>>> q;
        q.push({0,1});
        dist[0] = 1;
        int mod = 1e9+7;
        while(!q.empty()) {
            long long cost = q.top().second;
            int node = q.top().first;
            q.pop();
            for(auto i: adj[node]) {
                if(dist[i.first < (cost*i.second)%mod]) {
                    dist[i.first] = (cost*i.second)%mod;
                    q.push({i.first,(cost*i.second)%mod});
                }
            }
        }
        return dist;
    }
};