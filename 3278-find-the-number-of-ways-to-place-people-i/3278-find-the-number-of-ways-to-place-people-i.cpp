class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int> a,vector<int> b) {
            if(a[0] < b[0]) return true;
            else if(a[0] > b[0]) return false;
            else if(b[1] > a[1]) return false;
            return true;
        });
        // for(auto i: points) {
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }
        int cnt = 0;
        int n = points.size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(points[i][1] > points[j][1]) continue;
                bool flag = true;
                for(int x = 0; x<i; x++) {
                    if(x != j && points[i][0] >= points[x][0] && points[x][0] >= points[j][0] && points[x][1] >= points[i][1] && points[x][1] <= points[j][1]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) cnt++;
                //cout<<flag<<" "<<i<<" "<<j<<endl;
            }
        }
        return cnt;
    }
};