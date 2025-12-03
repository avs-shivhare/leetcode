class Solution {
public:
    long long find(unordered_map<long long,unordered_map<long long,long long>> &mpp) {
        long long ans = 0;
        for(auto i: mpp) {
            long long sum = 0;
            for(auto j: i.second) {
                sum += j.second;
            }
            for(auto j: i.second) {
                sum -= j.second;
                ans += j.second*sum;
            }
        }
        return ans;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long,unordered_map<long long,long long>> all,over;
        int n = points.size();
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                long long x = points[j][0]-points[i][0];
                long long y = points[j][1]-points[i][1];
                if(x < 0 || (x == 0 && y < 0)) {
                    x *= -1;
                    y *= -1;
                }
                long long g = gcd(x,llabs(y));
                long long sx = x/g;
                long long sy = y/g;
                long long des = sx*points[i][1]-sy*points[i][0];
                long long k = (sx <<12)+(sy+2000);
                long long k2 = (x<<12)+(y+2000);
                all[k][des]++;
                over[k2][des]++;
            }
        }
        return find(all)-find(over)/2;
    }
};