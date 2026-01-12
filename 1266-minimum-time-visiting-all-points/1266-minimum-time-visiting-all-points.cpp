class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int x = points[0][0];
        int y = points[0][1];
        int cnt = 0;
        for(int i = 1; i<n; i++) {
            if(x == points[i][0] && y == points[i][1]) continue;
            do{
                int a = abs(points[i][0]-x);
                int b = abs(points[i][1]-y);
                if(a == 0) a = 1e9;
                if(b == 0) b = 1e9;
                int mini = min(a,b);
                int nx = x;
                if(points[i][0] != x) nx += (points[i][0]-x < 0 ? -mini: mini);
                int ny = y;
                if(points[i][1] != y) ny += (points[i][1]-y < 0 ? -mini: mini);
                cnt += mini;
                x = nx;
                y = ny;
                //cout<<x<<" "<<y<<" "<<points[i][0]<<" "<<points[i][1]<<" "<<mini<<endl;
            }while(abs(x-points[i][0]) > 0 || abs(y-points[i][1]) > 0);
            // if(abs(x-points[i][0]) > 0 || abs(y-points[i][1]) > 0) {
            //     cnt++;
            //     x = points[i][0];
            //     y = points[i][1];
            // }
        }
        return cnt;
    }
};