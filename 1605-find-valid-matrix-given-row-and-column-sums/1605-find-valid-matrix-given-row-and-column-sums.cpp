class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int n = row.size();
        int m = col.size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> r,c;
        for(int i =0; i<n; i++) r.push({row[i],i});
        for(int i =0; i<m; i++) c.push({col[i],i});
        while(!r.empty() && !c.empty()) {
            auto x= r.top();
            auto y = c.top();
            //cout<<x.first<<" "<<x.second<<" "<<y.first<<" "<<y.second<<endl;
            r.pop();
            c.pop();
            int val = min(x.first,y.first);
            //cout<<val<<endl;
            ans[x.second][y.second] = val;
            if(x.first-val > 0) {
                r.push({x.first-val,x.second});
            }
            if(y.first-val > 0) {
                c.push({y.first-val,y.second});
            }
        }
        return ans;
    }
};