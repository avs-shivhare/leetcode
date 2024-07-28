class Solution {
public:
    int find(int step,int ti,int ch) {
        int ans =0;
        int p =0;
        for(int i =0; i<step; i++) {
            if((p/ch)%2 ==1) {
                ans += ch-(p%ch);
                p =0;
            }
            p += ti;
            ans += ti;
        }
        return ans;
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int ti, int ch) {
        vector<int> adj[n+1];
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> dist1(n+1,INT_MAX),dist2(n+1,INT_MAX);
        queue<pair<int,int>> q;
        q.push({1,0});
        while(!q.empty()) {
            int node = q.front().first;
            int cost = q.front().second;
            q.pop();
            int x =0;
            for(int i: adj[node]) {
                if(dist1[i] > cost+1) {
                    dist2[i] = dist1[i];
                    dist1[i] = cost+1;
                    q.push({i,cost+1});
                }
                else if(dist1[i] < cost+1 && dist2[i] > cost+1) {
                    dist2[i]= cost+1;
                    q.push({i,cost+1});
                }
            }
        }
        return find(dist2[n],ti,ch);
    }
};