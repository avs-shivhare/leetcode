class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<array<int,2>> temp;
        int m = queries.size();
        for(int i = 0; i<m; i++) {
            temp.push_back({queries[i],i});
        }
        sort(temp.begin(),temp.end());
        sort(logs.begin(),logs.end(),[&](auto &a,auto &b){
            if(a[1] != b[1]) return a[1] < b[1];
            else return a[0] <= b[0];
        });
        vector<int> ans(m,0);
        unordered_map<int,int> mpp;
        int l = 0,r = 0;
        m = logs.size();
        for(auto &i: temp) {
            int ql = i[0]-x;
            int qr = i[0];
            while(l < m && logs[l][1] < ql) {
                mpp[logs[l][0]]--;
                if(mpp[logs[l][0]] == 0) mpp.erase(logs[l][0]);
                l++;
            }
            while(r<m && logs[r][1] <= qr) {
                mpp[logs[r][0]]++;
                if(mpp[logs[r][0]] == 0) mpp.erase(logs[r][0]);
                r++;
            }
            ans[i[1]] = n-mpp.size();
        }
        return ans;
    }
};