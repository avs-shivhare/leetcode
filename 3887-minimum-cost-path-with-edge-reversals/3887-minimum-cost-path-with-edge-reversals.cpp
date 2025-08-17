class DSU{
    public:
    vector<int> parent,size;
    DSU(int n) {
        parent.resize(n,0);
        iota(parent.begin(),parent.end(),0);
        size.resize(n,1);
    }
    int Uparent(int n) {
        if(n == parent[n]) return n;
        return parent[n] = Uparent(parent[n]);
    }
    void add(int v,int u) {
        int Uu = Uparent(u);
        int Uv = Uparent(v);
        if(Uu == Uv) return;
        if(size[Uu] >= size[Uv]) {
            parent[Uv] = Uu;
            size[Uu] += size[Uv];
        }
        else {
            parent[Uu] = Uv;
            size[Uv] += size[Uu]; 
        }
    } 
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        DSU s(n);
        vector<pair<int,int>> adj[100001];
        vector<pair<int,int>> radj[100001];
        for(auto i: edges) {
            s.add(i[0],i[1]);
            adj[i[0]].push_back({i[1],i[2]});
            radj[i[1]].push_back({i[0],i[2]*2});
        }
        if(s.Uparent(0) != s.Uparent(n-1)) return -1;
        vector<vector<int>> dist(n,vector<int>(2,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        q.push({0,0});
        dist[0][0] = 0;
        dist[0][1] = 0;
        while(!q.empty()) {
            int node = q.top()[1];
            int cost = q.top()[0];
            q.pop();
            for(auto i: adj[node]) {
                if(dist[i.first][0] > cost+i.second) {
                    dist[i.first][0] = cost+i.second;
                    q.push({cost+i.second,i.first});
                }
            }
            for(auto i: radj[node]) {
                if(i.first != node && dist[i.first][1] > cost+i.second) {
                    dist[i.first][1] = cost+i.second;
                    q.push({cost+i.second,i.first});
                }
            }
        }
        return min(dist[n-1][0],dist[n-1][1]);
    }
};