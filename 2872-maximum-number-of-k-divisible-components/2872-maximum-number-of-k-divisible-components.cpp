class Solution {
public:
    int ans = 0;
    long long find(int node,int parent,vector<int> adj[],vector<int> &value,int &k) {
        long long sum = value[node];
        for(auto i: adj[node]) {
            if(parent != i) sum += find(i,node,adj,value,k);
        }
        if(sum%k == 0) {
            ans++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adj[n];
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        find(0,-1,adj,values,k);
        return ans;
    }
};