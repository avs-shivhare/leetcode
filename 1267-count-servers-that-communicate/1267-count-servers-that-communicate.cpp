class DisJoinSet {
    public:
    vector<int> size,parent;
    DisJoinSet(int n) {
        size.resize(n,1);
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int n) {
        if(parent[n] == n) return n;
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
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisJoinSet ds(n*m);
        vector<int> row(n,-1),col(m,-1);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j]) {
                    if(row[i] != -1) ds.add(i*m+j,i*m+row[i]);
                    if(col[j] != -1) ds.add(i*m+j,col[j]*m+j);
                    row[i] = j;
                    col[j] = i;
                }
            }
        }
        unordered_set<int> st;
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j]) {
                    int parent = ds.find(i*m+j);
                    if(ds.size[parent] > 1 && st.find(parent) == st.end()) {
                        ans += ds.size[parent];
                        st.insert(parent);
                    }
                }
            }
        }
        return ans;
    }
};