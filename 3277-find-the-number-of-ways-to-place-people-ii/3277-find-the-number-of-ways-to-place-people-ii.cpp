class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;
        sort(points.begin(),points.end(),[](vector<int> a,vector<int> b) {
            if(a[0] < b[0]) return true;
            else if(a[0] > b[0]) return false;
            else if(a[1] > b[1]) return true;
            return false;
        });
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(points[j][1] < points[i][1]) continue;
                bool flag = true;
                for(int x = j; x<i; x++) {
                    if(j == x) continue;
                    if(points[x][0] <= points[i][0] && points[j][0] <= points[x][0] && points[i][1] <= points[x][1] && points[x][1] <= points[j][1]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) cnt++;
            }
        }
        return cnt;
    }
};