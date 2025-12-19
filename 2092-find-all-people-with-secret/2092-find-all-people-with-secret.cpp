class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& edges, int f) {
        vector<int> dist(n,1e9);
        dist[0] = 0;
        dist[f] = 0;
        vector<vector<int>> adj[n];
        for(auto i: edges) {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        q.push({0,0});
        q.push({0,f});
        while(!q.empty()) {
            int t = q.top()[0];
            int node = q.top()[1];
            q.pop();
            if(dist[node] < t) continue;
            for(auto i: adj[node]) {
                if(dist[i[0]] > i[1] && t <= i[1]) {
                    dist[i[0]] = i[1];
                    q.push({i[1],i[0]});
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i<n; i++) {
            if(dist[i] < 1e9) ans.push_back(i);
        }
        return ans;
    }
};