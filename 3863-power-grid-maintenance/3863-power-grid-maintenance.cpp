class DSU{
    public:
    vector<int> parent,size;
    DSU(int n) {
        parent.resize(n+1,0);
        size.resize(n+1,1);
        iota(parent.begin(),parent.end(),0);
    }
    int Uparent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = Uparent(parent[n]);
    }
    void add(int a,int b) {
        int Ua = Uparent(a);
        int Ub = Uparent(b);
        if(Ua == Ub) return;
        if(size[Ua] > size[Ub]) {
            parent[Ub] = Ua;
            size[Ua] += size[Ub];
        }
        else {
            parent[Ua] = Ub;
            size[Ub] += size[Ua];
        }
        return;
    }
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        DSU u(c);
        for(auto i: edges) {
            u.add(i[0],i[1]);
        }
        unordered_map<int,set<int>> mpp;
        for(int i = 1; i<=c; i++) {
            mpp[u.Uparent(i)].insert(i);
        }
        vector<int> ans;
        for(auto i: queries) {
            if(i[0] == 1) {
                int parent = u.Uparent(i[1]);
                if(mpp[parent].count(i[1])) ans.push_back(i[1]);
                else if(mpp[parent].empty()) ans.push_back(-1);
                else {
                    ans.push_back(*(mpp[parent].begin()));
                }
            }
            else {
                int parent = u.Uparent(i[1]);
                mpp[parent].erase(i[1]);
            }
        }
        return ans;
    }
};