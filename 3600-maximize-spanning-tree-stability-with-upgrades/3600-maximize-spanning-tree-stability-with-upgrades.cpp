class DSU {
    public:
    vector<int> parent,size;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        size.resize(n,1);
    }
    int findParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }
    void add(int u,int v) {
        int Uu = findParent(u);
        int Uv = findParent(v);
        if(Uu == Uv) return;
        if(size[Uu] >= size[Uv]) {
            parent[Uv] = Uu;
            size[Uu] += size[Uv];
        }
        else {
            parent[Uu] = Uv;
            size[Uv] += size[Uu];
        }
        return;
    }
};
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU ds(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        int cnt = 0;
        vector<vector<int>> temp;
        for(auto &i: edges) {
            if(i[3] == 1) {
                if(ds.findParent(i[0]) == ds.findParent(i[1])) return -1;
                ds.add(i[0],i[1]);
                q.push({i[2],1});
                cnt++;
            }
            else {
                temp.push_back({i[2],i[0],i[1]});
            }
        }
        sort(temp.begin(),temp.end(),greater<vector<int>>());
        for(auto &i: temp) {
            if(ds.findParent(i[1]) != ds.findParent(i[2])) {
                ds.add(i[1],i[2]);
                q.push({i[0],0});
                cnt++;
            }
        }
        if(cnt != n-1) return -1;
        while(!q.empty() && k--) {
            if(q.top().second == 1) return q.top().first;
            auto x = q.top();
            q.pop();
            q.push({2*x.first,1});
        }
        return q.top().first;
    }
};