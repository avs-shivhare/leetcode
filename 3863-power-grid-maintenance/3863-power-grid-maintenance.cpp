class DisJoinSet {
    public:
    vector<int> size,parent;
    DisJoinSet(int n) {
        size.resize(n,1);
        parent.resize(n,0);
        iota(parent.begin(),parent.end(),0);
    }
    void add(int a,int b) {
        int ua = findParent(a);
        int ub = findParent(b);
        if(ua == ub) return;
        if(size[ua] > size[ub]) {
            parent[ub] = ua;
            size[ua] += size[ub];
        }
        else {
            parent[ua] = ub;
            size[ub] += size[ua];
        }
        return;
    }
    int findParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }
};
class Solution {
public:
    vector<int> processQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        DisJoinSet ds(n+1);
        for(auto  i: edges) {
            ds.add(i[0],i[1]);
        }
        map<int,set<int>> mpp;
        for(int i = 1; i<=n; i++) {
            mpp[ds.findParent(i)].insert(i);
        }
        vector<int> ans;
        for(auto i: q) {
            if(i[0] == 1) {
                int par = ds.findParent(i[1]);
                if(mpp[par].find(i[1]) != mpp[par].end()) ans.push_back(i[1]);
                else if(!mpp[par].empty()) ans.push_back(*(mpp[par].begin()));
                else ans.push_back(-1);
            }
            else {
                int par = ds.findParent(i[1]);
                mpp[par].erase(i[1]);
            }
        }
        return ans;
    }
};