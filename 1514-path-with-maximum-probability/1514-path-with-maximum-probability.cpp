class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        vector<pair<int,double>> adj[n];
        int si = succ.size();
        for(int i =0; i<si; i++) {
            adj[edges[i][0]].push_back({edges[i][1],succ[i]});
            adj[edges[i][1]].push_back({edges[i][0],succ[i]});
        } 
        priority_queue<pair<double,int>> q;
        vector<double> dist(n,0);
        dist[start] = 1;
        q.push({1,start});
        while(!q.empty()) {
            auto cost = q.top().first;
            auto node = q.top().second;
            q.pop();
            if(node == end) return cost;
            for(auto x: adj[node]) {
                double newCost = cost*x.second;
                if(dist[x.first] < newCost) {
                    dist[x.first] = newCost;
                    q.push({newCost,x.first});
                }
            }
        }
        return 0;
    }
};