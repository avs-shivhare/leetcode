class disJoint {
    public:
    vector<int> parent,size;
    disJoint(int n) {
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        size.resize(n,1);
    }
    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void add(int u,int v) {
        int Uu = findParent(u);
        int Uv = findParent(v);
        if(Uu == Uv) return;
        if(size[Uu] < size[Uv]) {
            parent[Uu] = Uv;
            size[Uv] += size[Uu];
        }
        else {
            parent[Uv] = Uu;
            size[Uu] += size[Uv];
        }
        return;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        disJoint ds(n+1);
        vector<int> ans = {0,0};
        for(auto i: edges) {
            if(ds.findParent(i[0]) == ds.findParent(i[1])) {
                ans = i;
            }
            else {
                ds.add(i[0],i[1]);
            }
        }
        return ans;
    }
};