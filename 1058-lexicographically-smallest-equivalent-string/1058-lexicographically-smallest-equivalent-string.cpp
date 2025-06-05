class Solution {
public:
    unordered_map<char,char> mpp;
    void dfs(int node,char &x,vector<char> adj[],vector<bool> &vis) {
        vis[node] = true;
        mpp[x] = min((char)(node+'a'),mpp[x]);
        for(auto i: adj[node]) {
            if(!vis[i-'a']) {
                dfs(i-'a',x,adj,vis);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string base) {
        vector<char> adj[26];
        int n = s1.size();
        for(int i = 0; i<n; i++) {
            adj[s1[i]-'a'].push_back(s2[i]);
            adj[s2[i]-'a'].push_back(s1[i]);
        }
        for(int i = 0; i<26; i++) {
            vector<bool> vis(26,false);
            mpp[i+'a'] = i+'a';
            char x = i+'a';
            dfs(i,x,adj,vis);
        }
        for(int i = 0; i<base.size(); i++) {
            base[i] = mpp[base[i]];
        }
        return base;
    }
};