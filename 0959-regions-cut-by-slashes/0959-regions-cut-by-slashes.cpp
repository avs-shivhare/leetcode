class disjointSet {
    vector<int> rank,parent,size;
    public:

    disjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i =0;i<=n; i++) {
            parent[i] =i;
        }
    }

    int findUparent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]);
    }
    void addbySize(int u,int v) {
        int Uu = findUparent(u);
        int Uv = findUparent(v);
        if(Uu == Uv) return;
        if(size[Uu] < size[Uv]) {
            parent[Uu] = Uv;
            size[Uv] += size[Uu];
        }
        else {
            parent[Uv] = Uu;
            size[Uu] += size[Uv];
        }
    }
    void addbyRank(int u,int v) {
        int Uu = findUparent(u);
        int Uv = findUparent(v);
        if(Uu == Uv) return;
        if(rank[Uu]<rank[Uv]) {
            parent[Uu] = Uv;
        }
        else if(rank[Uv] < rank[Uu]) {
            parent[Uv] = Uu;
        }
        else {
            parent[Uv] =Uu;
            rank[Uu]++;
        }
    }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size()+1;
        disjointSet st(n*n);
        for(int i =0; i<n; i++) {
            for(int j =0; j<n; j++) {
                if(i == 0 || j == 0 || i == n-1 || j == n-1) {
                    st.addbySize(i*n+j,0);
                }
            }
        }
        int ans =1;
        for(int i =0; i<n-1; i++) {
            for(int j =0; j<n-1; j++) {
                if(grid[i][j] == '\\') {
                    int upper = i*n+j;
                    int lower = (i+1)*n+(j+1);
                    if(st.findUparent(upper) == st.findUparent(lower)) ans++;
                    st.addbySize(upper,lower);
                }
                else if(grid[i][j] == '/') {
                    int upper = i*n+(j+1);
                    int lower = (i+1)*n+j;
                    if(st.findUparent(upper) == st.findUparent(lower)) ans++;
                    st.addbySize(upper,lower);
                    
                }
            }
        }
        return ans;
    }
};