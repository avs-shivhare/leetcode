class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n = ls.size();
        int m = ws.size();
        int ans = INT_MAX;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                int m1 = 0,m2 = 0;
                m1 = ls[i]+ld[i];
                if(m1 < ws[j]) m1 = ws[j]+wd[j];
                else m1 = m1+wd[j];
                m2 = ws[j]+wd[j];
                if(m2 < ls[i]) m2 = ls[i]+ld[i];
                else m2 = m2+ld[i];
                ans = min({ans,m1,m2});
            }
        }
        return ans;
    }
};