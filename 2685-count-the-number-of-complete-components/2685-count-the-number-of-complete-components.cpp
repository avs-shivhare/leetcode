class Union {
    public:
    vector<int> size,parent;
    Union(int n) {
        size.resize(n,1);
        parent.resize(n,0);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int n) {
        if(n == parent[n]) return n;
        return parent[n] = find(parent[n]);
    }
    void add(int a,int b) {
        int ua = find(a);
        int ub = find(b);
        if(ua == ub) return;
        if(size[ua] < size[ub]) swap(ua,ub);
        size[ua] += size[ub];
        parent[ub] = ua;
        return;
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        Union ds(n);
        vector<int> adj[n];
        for(auto &i: edges) {
            ds.add(i[0],i[1]);
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        unordered_map<int,vector<int>> mpp;
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            mpp[ds.find(i)].push_back(i);
        }
        for(auto &i: mpp) {
            bool flag = true;
            for(auto &j: i.second) {
                if(adj[j].size()+1 != i.second.size()) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};