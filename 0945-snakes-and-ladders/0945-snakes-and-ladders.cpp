class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int,int> adj;
        int maxi = 0;
        int n = board.size();
        int m = board[0].size();
        int l = 0,r = n-1;
        while(l<r) {
            swap(board[l],board[r]);
            l++;
            r--;
        }
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                int val = 0;
                if(i&1) {
                    val = i*m+(m-j);
                }
                else val = i*m+j+1;
                if(board[i][j] != -1) {
                    adj[val] = board[i][j];
                }
                maxi = max(maxi,val);
            }
        }
        vector<int> dist(maxi+1,1e9);
        queue<pair<int,int>> q;
        dist[1] = 0;
        q.push({0,1});
        while(!q.empty()) {
            int node = q.front().second;
            int cost = q.front().first;
            //cout<<node<<" "<<cost<<endl;
            q.pop();
            for(int i = node+1; i<=min(6+node,maxi); i++) {
                if(adj.count(i)) {
                    if(dist[adj[i]] > cost+1) {
                        dist[adj[i]] = cost+1;
                        q.push({cost+1,adj[i]});
                    } 
                }
                else {
                    if(dist[i] > cost+1) {
                        dist[i] = cost+1;
                        q.push({cost+1,i});
                    }
                }
            }
        }
        if(dist[maxi] >= 1e9) return -1;
        return dist[maxi];
    }
};