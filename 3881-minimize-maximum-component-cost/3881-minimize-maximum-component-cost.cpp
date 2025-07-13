class DSU {
    public:
        vector<int> size,parent;
        DSU(int n) {
            size.resize(n,1);
            parent.resize(n,0);
            iota(parent.begin(),parent.end(),0);
        }
        int Uparent(int n) {
            if(n == parent[n]) return n;
            return parent[n] = Uparent(parent[n]);
        }
        void add(int x,int y) {
            int ux = Uparent(x);
            int uv = Uparent(y);
            if(ux == uv) return;
            if(size[ux] > size[uv]) {
                parent[uv] = ux;
                size[ux] += size[uv];
            }
            else {
                parent[ux] = uv;
                size[uv] += size[ux];
            }
            return;
        }
};

class Solution {
public:
    bool check(vector<vector<int>> &edges,int k,int mid,int &n) {
        DSU u(n);
        for(auto &i: edges) {
            if(i[2] <= mid) u.add(i[0],i[1]);
        }
        unordered_set<int> st;
        for(int i = 0; i<n; i++) {
            st.insert(u.Uparent(i));
        }
        return st.size() <= k;
    } 
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int l = 0,r = n;
        int ans = 0;
        for(auto &i: edges) r = max(i[2],r);
        while(l<=r) {
            int mid = (l+r)>>1;
            if(check(edges,k,mid,n)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};