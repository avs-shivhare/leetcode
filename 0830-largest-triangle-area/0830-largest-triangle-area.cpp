class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        int n = points.size();
        for(int i = 0; i<n; i++) {
            for(int j =i+1; j<n; j++) {
                for(int x = j+1; x<n; x++) {
                    double a = points[i][0]*(points[j][1]-points[x][1]);
                    double b = points[j][0]*(points[x][1]-points[i][1]);
                    double c = points[x][0]*(points[i][1]-points[j][1]);
                    double temp = 0.5*abs(a+b+c);
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};