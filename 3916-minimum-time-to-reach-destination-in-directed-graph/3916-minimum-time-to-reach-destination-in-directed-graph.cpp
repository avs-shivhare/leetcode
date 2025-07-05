class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj[100001];
        for(auto i: edges) {
            adj[i[0]].push_back({i[1],i[2],i[3]});
        }
        queue<pair<long long,int>> q;
        vector<long long> dist(n,1e18);
        dist[0] = 0;
        q.push({0,0});
        while(!q.empty()) {
            long long cost = q.front().first;
            int node = q.front().second;
            //cout<<node<<" "<<cost<<endl;
            q.pop();
            for(auto i: adj[node]) {
                if(cost > i[2]) continue;
                long long newcost = max((long long)i[1],cost)+1;
                if(dist[i[0]] > newcost) {
                    dist[i[0]] = newcost;
                    q.push({newcost,i[0]});
                }
            }
        }
        if(dist[n-1] >= 1e18) return -1;
        return dist[n-1];
    }
};