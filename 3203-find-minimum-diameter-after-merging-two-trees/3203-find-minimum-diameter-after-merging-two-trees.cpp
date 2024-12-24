class Solution {
public:
    int dig = 0;
    int dfs(int node,int parent,vector<int> adj[]) {
        int first = 0,second = 0;
        for(auto i: adj[node]) {
            if(i != parent) {
                int temp = dfs(i,node,adj);
                if(temp > first) {
                    second = first;
                    first = temp;
                }
                else if(temp <= first && temp > second) {
                    second = temp;
                }
            }
        }
        dig = max(dig,first+second+1);
        //cout<<node<<" "<<first+second+1<<endl;
        return first+1;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
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
        dig = 0;
        dfs(0,-1,adj);
        //cout<<dig<<endl;
        int firstDig = dig-1;
        int first = ceil((double)firstDig/(double)2);
        dig = 0;
        //cout<<"second tree"<<endl;
        dfs(0,-1,adj2);
        //cout<<dig<<endl;
        int secondDig = dig-1;
        int second = ceil((double)secondDig/(double)2);
        //cout<<firstDig<<" dig "<<secondDig<<endl;
        return max({first+second+1,firstDig,secondDig});
    }
};