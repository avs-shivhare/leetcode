class DisJointSet{
    public:
    vector<int> size,parent;
    DisJointSet(int n) {
        size.resize(n,1);
        parent.resize(n,0);
        iota(parent.begin(),parent.end(),0);
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
        else {
            parent[Uu] = Uv;
            size[Uv] += size[Uu];
        }
    }
};

class Solution {
public:
    bool check(vector<int> &a,vector<int> &b,int &k) {
        unordered_set<int> st;
        int cnt = 0;
        for(auto i: a) {
            st.insert(i);
        }
        for(auto i: b) {
            if(st.count(i)) {
                cnt++;
                st.erase(i);
            }
        }
        return cnt >= k;
    }
    int numberOfComponents(vector<vector<int>>& pro, int k) {
        int n = pro.size();
        DisJointSet ds(n);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i == j) continue;
                if(ds.find(i) == ds.find(j)) continue;
                if(check(pro[i],pro[j],k)) {
                    ds.add(i,j);
                }
            }
        }
        unordered_set<int> st;
        for(int i = 0; i<n; i++) {
            st.insert(ds.find(i));
        }
        return st.size();
    }
};