class SG {
    public:
    vector<int> sg;
    SG(int n) {
        sg.resize(4*n+1,0);
    }
    void update(int l,int r,int ind,int &index,int &val) {
        if(l == r) {
            if(l == index) sg[ind] = val;
            return;
        }
        int mid = (l+r)>>1;
        if(index <= mid) update(l,mid,2*ind+1,index,val);
        else update(mid+1,r,2*ind+2,index,val);
        sg[ind] = sg[2*ind+1]^sg[2*ind+2];
    }
    int query(int l,int r,int ql,int qr,int ind) {
        if(r < ql || l > qr) return 0;
        if(ql <= l && r <= qr) return sg[ind];
        int mid = (l+r)>>1;
        return query(l,mid,ql,qr,2*ind+1)^query(mid+1,r,ql,qr,2*ind+2);
    }
};

class Solution {
public:
    vector<int> parent,depth,heavy,head,pos,val;
    int curr;

    int dfs(int node,int par,int d,vector<int> adj[]) {
        depth[node] = d;
        parent[node] = par;
        int size = 1;
        int maxi = 0;
        for(auto &i: adj[node]) {
            if(i != par) {
                int temp = dfs(i,node,d+1,adj);
                size += temp;
                if(temp > maxi) {
                    maxi = temp;
                    heavy[node] = i;
                }
            }
        }
        return size;
    }

    void decompose(int node,int h,vector<int> adj[]) {
        head[node] = h;
        pos[node] = curr++;
        if(heavy[node] != -1) decompose(heavy[node],h,adj);
        for(auto &i: adj[node]) {
            if(i != parent[node] && i != heavy[node]) decompose(i,i,adj);
        }
    }

    int query(int u,int v,SG &sg,int &n) {
        int ans = 0;
        while(head[u] != head[v]) {
            if(depth[head[u]] > depth[head[v]]) {
                swap(u,v);
            }
            ans ^= sg.query(0,n-1,pos[head[v]],pos[v],0);
            v = parent[head[v]];
        }
        if(depth[u] > depth[v]) {
            swap(u,v);
        }
        ans ^= sg.query(0,n-1,pos[u],pos[v],0);
        return ans;
    }
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<int> adj[n];
        for(auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        parent.resize(n,0);
        depth.resize(n,0);
        heavy.resize(n,-1);
        head.resize(n,0);
        pos.resize(n,0);
        dfs(0,-1,0,adj);
        curr = 0;
        decompose(0,0,adj);
        SG sg(n);
        val.resize(n);
        for(int i = 0; i<n; i++) {
            val[i] = 1<<(s[i]-'a');
            sg.update(0,n-1,0,pos[i],val[i]);
        }
        vector<bool> ans;
        for(auto &i: queries) {
            stringstream ss(i);
            string type;
            ss>>type;
            if(type == "update") {
                int u;
                char c;
                ss>>u>>c;
                val[u] = 1<<(c-'a');
                sg.update(0,n-1,0,pos[u],val[u]);
            }
            else {
                int u,v;
                ss>>u>>v;
                int mask = query(u,v,sg,n);
                ans.push_back((mask & (mask-1)) == 0);
            }
        }
        return ans;
    }
};