class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj[100001];
        vector<vector<int>> radj[100001];
        for(auto &i: edges) {
            adj[i[0]].push_back({i[1],i[2]});
            radj[i[1]].push_back({i[0],i[2]*2});
        }
        vector<int> dist(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        dist[0] = 0;
        q.push({0,0});
        while(!q.empty()) {
            int node = q.top()[1];
            int cost = q.top()[0];
            q.pop();
            if(dist[node] < cost) continue;
            for(auto &i: adj[node]) {
                if(dist[i[0]] > cost+i[1]) {
                    dist[i[0]] = cost+i[1];
                    q.push({dist[i[0]],i[0]});
                }
            }
            for(auto &i: radj[node]) {
                if(dist[i[0]] > cost+i[1]) {
                    dist[i[0]] = cost+i[1];
                    q.push({dist[i[0]],i[0]});
                }
            }
        }
        if(dist[n-1] >= INT_MAX) return -1;
        return dist[n-1];
    }
};