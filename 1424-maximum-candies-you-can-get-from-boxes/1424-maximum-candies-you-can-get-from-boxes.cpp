class Solution {
public:
    queue<int> q;
    unordered_set<int> st,st2;
    void dfs(int node,vector<vector<int>> &box,vector<vector<int>> &key,vector<bool> &vis) {
        vis[node] = true;
        for(auto i: box[node]) {
            if(!vis[i] && st.count(i)) {
                q.push(i);
                st.erase(i);
            }
            else {
                st2.insert(i);
            }
        }
        for(auto i: key[node]) {
            if(!vis[i] && st2.count(i)) {
                q.push(i);
                st2.erase(i);
            }
            else {
                st.insert(i);
            }
        }
        return;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        for(int i = 0; i<n; i++) {
            if(status[i] == 1) st.insert(i);
        }
        vector<bool> vis(n,false);
        for(auto i: initialBoxes) {
            if(st.count(i)) {
                q.push(i);
                st.erase(i);
            }
            else st2.insert(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(!vis[node]) dfs(node,containedBoxes,keys,vis);
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            if(vis[i]) ans += candies[i];
        }
        return ans;
    }
};