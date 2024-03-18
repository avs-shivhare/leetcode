class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),[](const auto &a,const auto &b) {
            return a[0] < b[0];
        });
        int ans =1;
        int end = points[0][1];
        for(int i =0; i<n;i++) {
            if(end < points[i][0]) {
                end = points[i][1];
                ans++;
            }
            else end = min(end,points[i][1]);
        }
        return ans;
    }
};