class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> adj[n];
        vector<int> degree(n,0);
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            degree[i[0]]++;
            degree[i[1]]++;
        }
        // for(auto i:adj) {
        //     for(auto j: i) {
        //         cout<<j<<"->";
        //     }
        //     cout<<endl;
        // }
        queue<int> q;
        for(int i =0; i<n; i++) {
            if(degree[i] == 1) q.push(i);
        }
        while(n>2) {
            int sz = q.size();
            n -= sz;
            while(sz--) {
                int node = q.front();
                q.pop();
                for(int i: adj[node]) {
                    degree[i]--;
                    if(degree[i] == 1) q.push(i);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};