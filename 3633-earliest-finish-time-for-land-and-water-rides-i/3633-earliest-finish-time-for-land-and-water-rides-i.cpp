class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int ans = 1e9;
        int n = ls.size();
        int m = ws.size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                int lw = ls[i]+ld[i];
                lw = max(lw,ws[j])+wd[j];
                int wl = ws[j]+wd[j];
                wl = max(wl,ls[i])+ld[i];
                ans = min({ans,lw,wl});
            }
        }
        return ans;
    }
};