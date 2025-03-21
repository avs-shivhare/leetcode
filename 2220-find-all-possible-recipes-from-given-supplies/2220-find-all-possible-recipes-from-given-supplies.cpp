class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> in;
        int n = rec.size();
        for(int i = 0; i<n; i++) {
            for(auto j: ing[i]) {
                adj[j].push_back(rec[i]);
                in[rec[i]]++;
            }
        }
        queue<string> q;
        for(auto i: sup) {
            if(in[i] == 0) q.push(i);
            in.erase(i);
        }
        while(!q.empty()) {
            auto node = q.front();
            //cout<<node<<endl;
            q.pop();
            for(auto i: adj[node]) {
                in[i]--;
                if(in[i] == 0) {
                    q.push(i);
                    in.erase(i);
                }
            }
        }
        vector<string> ans;
        for(auto i: rec) {
            if(in.count(i) == 0) ans.push_back(i);
        }
        return ans;
    }
};