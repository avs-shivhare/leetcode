class DSU {
    public:
    vector<int> size,parent;
    DSU(int n) {
        size.resize(n,1);
        parent.resize(n,0);
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
    bool check(vector<vector<int>> &edges,long long mid,int k,int &n) {
        DSU u(n);
        int x = edges.size();
        for(int i = 0; i<x; i++) {
            if(edges[i][2] <= mid) continue;
            u.add(edges[i][1],edges[i][0]);
        }
        unordered_set<int> st;
        for(int i = 0; i<n; i++) {
            st.insert(u.Uparent(i));
        }
        return st.size() >= k;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        long long l = 0,r = 0;
        int x = edges.size();
        for(int i = 0; i<x; i++) {
            r = max(r,(long long)edges[i][2]);
        }
        long long ans = 0;
        while(l<=r) {
            long long mid = (l+r)>>1;
            if(check(edges,mid,k,n)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};