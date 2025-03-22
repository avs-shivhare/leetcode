class DisJointSet{
    public:
    vector<int> parent,size;
    DisJointSet(int n) {
        parent.resize(n,0);
        iota(parent.begin(),parent.end(),0);
        size.resize(n,1);
    }
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void add(int u,int v) {
        int Uu = find(u);
        int Uv = find(v);
        if(Uu == Uv) return;
        if(size[Uu] > size[Uv]) {
            parent[Uv] = Uu;
            size[Uu] += size[Uv];
        }
        else{
            parent[Uu] = Uv;
            size[Uv] += size[Uu];
        }
        return;
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[51];
        DisJointSet ds(n);
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            if(ds.find(i[0]) != ds.find(i[1])) {
                ds.add(i[0],i[1]);
            }
        }
        unordered_map<int,vector<int>> mpp;
        for(int i = 0; i<n; i++) {
            mpp[ds.find(i)].push_back(i);
        }
        int cnt = 0;
        for(auto i: mpp) {
            bool flag = true;
            for(auto j: i.second) {
                if(ds.size[i.first]-1 != adj[j].size()) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};