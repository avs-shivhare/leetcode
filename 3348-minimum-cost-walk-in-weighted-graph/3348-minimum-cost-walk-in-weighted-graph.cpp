class DisJointSet{
    public:
    vector<int> parent,size,ans;
    DisJointSet(int n) {
        parent.resize(n,0);
        iota(parent.begin(),parent.end(),0);
        size.resize(n,1);
        ans.resize(n,INT_MAX);
    }
    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void add(int u,int v,int wt) {
        int Uu = find(u);
        int Uv = find(v);
        if(Uu == Uv) {
            ans[Uu] &= wt;
            return;
        }
        if(size[Uu] > size[Uv]) {
            parent[Uv] = Uu;
            size[Uu] += size[Uv];
            ans[Uu] &= ans[Uv] & wt;
        }
        else {
            parent[Uu] = Uv;
            size[Uv] += size[Uu];
            ans[Uv] &= ans[Uu] & wt;
        }
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisJointSet ds(n);
        for(auto i: edges) {
            ds.add(i[0],i[1],i[2]);
        }
        vector<int> ans;
        for(auto i: query) {
            if(ds.find(i[0]) == ds.find(i[1])) {
                ans.push_back(ds.ans[ds.find(i[0])]);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};