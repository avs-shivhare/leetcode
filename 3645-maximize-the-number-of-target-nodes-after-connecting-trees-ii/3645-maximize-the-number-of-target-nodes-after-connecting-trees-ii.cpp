class Solution {
public:
    void dfs(int node,int par,vector<int> adj[],vector<int> &color,int &eCnt,int &oCnt) {
        if(color[node] == 0) eCnt++;
        else oCnt++;
        for(auto i: adj[node]) {
            if(i != par) {
                color[i] = color[node]^1;
                dfs(i,node,adj,color,eCnt,oCnt);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> adj[100001];
        vector<int> adj2[100001];
        for(auto i: edges1) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(auto i: edges2) {
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        int evenA = 0,oddA = 0,evenB = 0,oddB = 0;
        vector<int> colorA(n,-1),colorB(m,-1);
        colorA[0] = 0;
        colorB[0] = 0;
        dfs(0,-1,adj,colorA,evenA,oddA);
        dfs(0,-1,adj2,colorB,evenB,oddB);
        vector<int> ans(n);
        for(int i = 0; i<n; i++) {
            ans[i] = (colorA[i] == 0? evenA: oddA)+max(evenB,oddB);
        }
        return ans;
    }
};