class disjointSet {
    public:
    vector<int> rank,parent,size;

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
    static bool compare(vector<int> t1,vector<int> t2) {
        if(t1[0] > t2[0]) return true;
        return false;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0;
        sort(edges.begin(),edges.end(),compare);
        disjointSet a(n+1),b(n+1);
        for(auto i: edges) {
            int type = i[0];
            int u = i[1];
            int v = i[2];
            if(type == 3) {
                if(a.findUparent(u) != a.findUparent(v)) {
                    a.addbySize(u,v);
                }
                else ans++;
                if(b.findUparent(u) != b.findUparent(v)) {
                    b.addbySize(u,v);
                } 
            }
            if(type == 1) {
                if(a.findUparent(u) != a.findUparent(v)) {
                    a.addbySize(u,v);
                }
                else ans++;
            }
            if(type == 2) {
                if(b.findUparent(u) != b.findUparent(v)) {
                    b.addbySize(u,v);
                }
                else ans++;
            }
        }
        int alice = a.findUparent(1);
        int bob = b.findUparent(1);
        //cout<<alice<<" "<<bob<<endl;
        for(int i = 1; i<=n; i++) {
            if(alice != a.findUparent(i)) return -1;
            if(bob != b.findUparent(i)) return -1;
        }
        return ans;
    }
};