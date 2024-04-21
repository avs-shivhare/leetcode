class Solution {
public:
    bool dfs(int source,int &destination,vector<int> arr[],vector<bool> &vis) {
        if(source == destination) return true;
        vis[source] = true;
        for(int i : arr[source]) {
            if(!vis[i]) {
                if(dfs(i,destination,arr,vis)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> arr[n];
        for(auto i: edges) {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n,false);
        return dfs(source,destination,arr,vis);
    }
};