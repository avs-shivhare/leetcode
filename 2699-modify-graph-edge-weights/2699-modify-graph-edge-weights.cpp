class Solution {
public:
    int maxi = 2*1e9;
    int find(vector<pair<int,int>> adj[],int src,int des,int &n) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        q.push({0,src});
        while(!q.empty()) {
            int cost =q.top().first;
            int node = q.top().second;
            q.pop();
            if(node == des) return cost;
            for(auto i: adj[node]) {
                if(dist[i.first] > cost+i.second) {
                    dist[i.first] = cost+i.second;
                    q.push({cost+i.second,i.first});
                }
            } 
        }
        return maxi;
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        vector<pair<int,int>> adj[n];
        int si = edges.size();
        for(auto i: edges) {
            if(i[2] == -1) continue;
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        int curr = find(adj,src,dest,n);
        if(curr < target) return {};
        for(auto &i: edges) {
            if(i[2] != -1) continue;
            if(curr == target) {
                i[2] = maxi;
                continue;
            }
            i[2] = 1;
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],1});
            curr = find(adj,src,dest,n);
            if(curr <= target) {
                i[2] += target-curr;
                curr = target;
            }
        }
        if(target == curr) return edges;
        return {};
    }
};