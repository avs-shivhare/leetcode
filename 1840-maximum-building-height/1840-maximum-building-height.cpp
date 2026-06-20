class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        res.push_back({1,0});
        res.push_back({n,n-1});
        sort(res.begin(),res.end());
        long long ans = 0;
        int m = res.size();
        for(int i = 1; i<m; i++) {
            if(res[i][1] > res[i-1][1]) {
                res[i][1] = min(res[i][1],res[i-1][1]+(res[i][0]-res[i-1][0]));
            }
        }
        for(int i = m-2; i>=0; i--) {
            if(res[i][1] > res[i+1][1]) {
                res[i][1] = min(res[i][1],res[i+1][1]+(res[i+1][0]-res[i][0]));
            }
        }
        // for(auto i: res) cout<<i[1]<<" ";
        // cout<<endl;
        for(int i = 1; i<m; i++) {
            long long diff = 1ll*res[i][0]-res[i-1][0];
            long long diffh = abs(1ll*res[i-1][1]-res[i][1]);
            diff -= diffh;
            ans = max(ans,max(res[i][1],res[i-1][1])+(diff>>1));
            //cout<<ans<<endl;
        }
        // long long diff = 1ll*n-res.back()[0];
        // //cout<<diff<<endl;
        // ans = max(ans,res.back()[1]+diff);
        return ans;
    }
};