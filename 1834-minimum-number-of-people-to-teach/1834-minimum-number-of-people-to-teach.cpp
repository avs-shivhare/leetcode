class Solution {
public:
    bool check(vector<int> &a,vector<int> &b) {
        unordered_set<int> st(a.begin(),a.end());
        for(auto &i: b) {
            if(st.find(i) != st.end()) return true;
        }
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& lan, vector<vector<int>>& fr) {
        map<int,unordered_set<int>> adj;
        for(auto i: fr) {
            if(!check(lan[i[0]-1],lan[i[1]-1])) {
                //cout<<i[0]<<" "<<i[1]<<endl;
                adj[i[0]].insert(i[1]);
                adj[i[1]].insert(i[0]);
            }
        }
        int m = lan.size();
        map<int,unordered_set<int>> mpp;
        for(int i = 0; i<m; i++) {
            mpp[i+1].insert(lan[i].begin(),lan[i].end());
        }
        int ans = 1e9;
        for(int i = 1; i<=n; i++) {
            int cnt = 0;
            for(int node = 1; node<=m; node++) {
                if(adj[node].size() == 0) continue;
                if(mpp[node].find(i) == mpp[node].end()) {
                    cnt++;
                    // cout<<node<<" ";
                }
            }
            // cout<<endl;
            // cout<<i<<" "<<cnt<<endl;
            ans = min(ans,cnt);
        }
        return ans;
    }
};