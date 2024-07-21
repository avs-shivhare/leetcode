class Solution {
public:
    bool dfs(int node,int parent,vector<int> adj[],vector<bool> &vis,vector<bool> &path) {
        vis[node] = true;
        path[node] = true;
        for(auto i: adj[node]) {
            if(!vis[i]) {
                if(dfs(i,node,adj,vis,path)) return true;
            }
            else if(i == node)  {

            }
            else if(path[i]) return true;
        }
        path[node] = false;
        return false;
    }
    void dfs2(int node,vector<int> adj[],vector<bool> &vis,vector<int> &st) {
        vis[node] = true;
        //cout<<node<<endl;
        for(auto i: adj[node]) {
            if(!vis[i]) dfs2(i,adj,vis,st);
        }
        st.push_back(node);
    }
    void print(vector<int> adj[],int k) {
        for(int i =1; i<=k; i++) {
            cout<<i<<"-> ";
            for(auto j: adj[i]) cout<<j<<" ";
            cout<<endl;
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        vector<bool> vis(k+1,false),path(k+1,false);
        vector<int> rowadj[k+1],coladj[k+1];
        for(auto i: row) {
            rowadj[i[0]].push_back(i[1]);
        }
        for(auto i: col) {
            coladj[i[0]].push_back(i[1]);
        }
        // print(rowadj,k);
        // print(coladj,k);
        for(int i =1; i<=k; i++) {
            if(!vis[i]) {
                if(dfs(i,-1,rowadj,vis,path)) return {};
            }
        }
        for(int i =1; i<=k; i++) vis[i] = false;
        for(int i =1; i<=k; i++) {
            if(!vis[i]) {
                if(dfs(i,-1,coladj,vis,path)) return {};
            }
        }
        vector<int> temp1,temp2;
        for(int i =1; i<=k; i++) vis[i] = false;
        for(int i =1; i<=k; i++) {
            if(!vis[i]) {
                dfs2(i,rowadj,vis,temp1);
            }
        }
        reverse(temp1.begin(),temp1.end());
        //cout<<"row"<<endl;
        //for(auto i: temp1) cout<<i<<endl;
        for(int i =1; i<=k; i++) vis[i] = false;
        for(int i =1; i<=k; i++) {
            if(!vis[i]) {
                dfs2(i,coladj,vis,temp2);
            }
        }
        reverse(temp2.begin(),temp2.end());
        //cout<<"col"<<endl;
        //for(auto i: temp2) cout<<i<<endl;
        unordered_map<int,int> mpp;
        int n = temp1.size();
        for(int i =0; i<n; i++) {
            mpp[temp1[i]] = i;
        }
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i = 0; i<temp2.size(); i++) {
            ans[mpp[temp2[i]]][i] = temp2[i];
        }
        return ans;
    }
};