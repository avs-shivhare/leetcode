class Solution {
public:
    vector<int> adj[1001];
    vector<unordered_set<int>> child;
    vector<long long> subTree;
    long long dfs(int node,int par,vector<int> &nums) {
        subTree[node] = nums[node];
        child[node].insert(node);
        for(auto i: adj[node]) {
            if(i != par) {
                subTree[node] ^= dfs(i,node,nums);
                child[node].insert(child[i].begin(),child[i].end());
            }
        }
        return subTree[node];
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        child.resize(n);
        subTree.resize(n,0);
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        long long total = dfs(0,-1,nums);
        long long ans = 1e18;
        // cout<<total<<endl;
        // for(int i = 0; i<n; i++) {
        //     cout<<i<<" -> "<<subTree[i]<<endl;
        // }
        for(int i = 1; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                long long a,b,c;
                if(child[i].count(j)) {
                    a = subTree[j];
                    b = subTree[i]^subTree[j];
                    c = total^subTree[i];
                }
                else if(child[j].count(i)) {
                    a = subTree[i];
                    b = subTree[j]^subTree[i];
                    c = total ^ subTree[j];
                }
                else {
                    a = subTree[i];
                    b = subTree[j];
                    c = total ^ subTree[i] ^ subTree[j];
                }
                ans = min(max({a,b,c})-min({a,b,c}),ans);
            }
        }
        return ans;
    }
};