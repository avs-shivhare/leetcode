class DSU {
    public:
    vector<int> parent,size;
    DSU(int n,vector<int> &nums) {
        parent.resize(n,0);
        size = nums;
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
    vector<int> adj[14];
    int n;
    int cnt = 0;
    unordered_set<int> st;
    void check(vector<int> &nums) {
        DSU ds(n,nums);
        for(auto &i: st) {
            for(auto j: adj[i]) {
                if(st.find(j) != st.end()) ds.add(i,j);
            }
        }
        int par = -1;
        for(auto &i: st) {
            if(par == -1) par = ds.findParent(i);
            else if(par != ds.findParent(i)) return;
        }
        if(ds.size[par]%2 == 0) cnt++;
        return;
    }
    void find(int i,int &n,vector<int> &nums) {
        if(i == n) {
            if(st.empty()) return;
            check(nums);
            return;
        }
        st.insert(i);
        find(i+1,n,nums);
        st.erase(i);
        find(i+1,n,nums);
        return;
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        for(auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        find(0,n,nums);
        return cnt;
    }
};