class Solution {
public:
    void dfs(int node,vector<vector<int>> &graph,vector<int> &temp,vector<vector<int>> &ans,int &target) {
        if(node == target) {
            ans.push_back(temp);
            return;
        }
        for(int i: graph[node]) {
            temp.push_back(i);
            dfs(i,graph,temp,ans,target);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size()-1;
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        dfs(0,graph,temp,ans,n);
        return ans;
    }
};