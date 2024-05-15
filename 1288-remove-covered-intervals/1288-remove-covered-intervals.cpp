class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        int n = inter.size();
        int ans = 0;
        int i =0;
        while(i<n) {
            int j = i+1;
            int start = inter[i][0];
            int end = inter[i][1];
            while(j<n && ((start <= inter[j][0] && inter[j][1] <= end) || (inter[j][0] <= start && end <= inter[j][1]))) {
                start = min(start,inter[j][0]);
                end = max(end,inter[j][1]);
                j++;
            }
            i =j;
            ans++;
        }
        return ans;
    }
};