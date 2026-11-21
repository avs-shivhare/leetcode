class Solution {
public:
    unordered_map<char,vector<int>> mpp;
    vector<int> anc;
    vector<int> ans;
    void dfs(int node,unordered_set<int> adj[],string &s) {
        if(!mpp[s[node]].empty()) {
            anc[node] = mpp[s[node]].back();
        }
        mpp[s[node]].push_back(node);
        for(auto &i: adj[node]) {
            //mpp[s[node]] = node;
            dfs(i,adj,s);
        }
        mpp[s[node]].pop_back();
    }
    int dfs2(int node,unordered_set<int> adj[]) {
        int temp = 1;
        for(auto &i: adj[node]) {
            temp += dfs2(i,adj);
        }
        return ans[node] = temp;
    } 
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        anc.resize(n,-1);
        ans.resize(n,0);
        unordered_set<int> adj[n];
        for(int i = 1; i<n; i++) {
            adj[parent[i]].insert(i);
        }
        dfs(0,adj,s);
        for(int i = 1; i<n; i++) {
            if(anc[i] == -1) continue;
            adj[parent[i]].erase(i);
            adj[anc[i]].insert(i);
        }
        dfs2(0,adj);
        return ans;
    }
};