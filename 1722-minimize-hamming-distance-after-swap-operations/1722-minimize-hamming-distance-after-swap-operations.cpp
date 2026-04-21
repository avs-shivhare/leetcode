class DSU {
    public:
    vector<int> size,parent;
    DSU(int n) {
        size.resize(n,1);
        parent.resize(n,0);
        iota(parent.begin(),parent.end(),0);
    }
    int findParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
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
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& a) {
        int n = s.size();
        DSU ds(n);
        for(auto &i: a) {
            ds.add(i[0],i[1]);
        }
        map<int,map<int,int>> mpp;
        for(int i = 0; i<n; i++) {
            mpp[ds.findParent(i)][s[i]]++;
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            int p = ds.findParent(i);
            if(mpp[p][t[i]]) {
                mpp[p][t[i]]--;
            }
            else ans++;
        }
        return ans;
    }
};