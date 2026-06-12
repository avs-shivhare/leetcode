class SG {
    public:
    vector<int> sg;
    vector<int> h;
    SG(int n,vector<int> &arr) {
        sg.resize(4*n+1,0);
        h = arr;
    }
    void build(int l,int r,vector<int> &arr,int ind) {
        if(l == r) {
            sg[ind] = arr[l];
            return;
        }
        int mid = (l+r)>>1;
        build(l,mid,arr,2*ind+1);
        build(mid+1,r,arr,2*ind+2);
        if(h[sg[2*ind+1]] <= h[sg[2*ind+2]]) {
            sg[ind] = sg[2*ind+1];
        }
        else sg[ind] = sg[2*ind+2];
        return;
    }
    int query(int l,int r,int ql,int qr,int ind) {
        if(l > r || r < ql || l > qr) return 1e9;
        if(ql <= l && r <= qr) return sg[ind];
        int mid = (l+r)>>1;
        int lf = query(l,mid,ql,qr,2*ind+1);
        int rf = query(mid+1,r,ql,qr,2*ind+2);
        if(lf >= 1e9) return rf;
        if(rf >= 1e9) return lf;
        if(h[lf] <= h[rf]) return lf;
        return rf;
    }
};
class Solution {
public:
    vector<int> ver,height;
    int mod = 1e9+7;
    void dfs(int node,int par,vector<int> adj[],int he) {
        height[node] = he;
        ver.push_back(node);
        for(auto &i: adj[node]) {
            if(i != par) {
                dfs(i,node,adj,he+1);
                ver.push_back(node);
            }
        }
        return;
    }
    long long power(long long a,long long b) {
        if(b == 0) return 1;
        if(b == 1) return a;
        long long ans = power(a,b>>1ll);
        if(b&1ll) return (((ans*ans)%mod)*a)%mod;
        return (ans*ans)%mod;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<int> adj[100001];
        for(auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int n = edges.size()+1;
        height.resize(n+1,0);
        dfs(1,-1,adj,1);
        n = ver.size();
        SG s(n,height);
        s.build(0,n-1,ver,0);
        vector<int> ans;
        unordered_map<int,int> first,second;
        for(int i = 0; i<n; i++) {
            if(first.find(ver[i]) == first.end()) {
                first[ver[i]] = i;
            }
            second[ver[i]] = i;
        }
        for(auto &i: queries) {
            int com = s.query(0,n-1,min(first[i[0]],first[i[1]]),max(second[i[0]],second[i[1]]),0);
            int dist = height[i[0]]-height[com]+height[i[1]]-height[com];
            //cout<<i[0]<<" "<<i[1]<<" "<<dist<<endl;
            if(dist > 0)ans.push_back(power(2ll,dist-1));
            else ans.push_back(0);
        }
        return ans;
    }
};