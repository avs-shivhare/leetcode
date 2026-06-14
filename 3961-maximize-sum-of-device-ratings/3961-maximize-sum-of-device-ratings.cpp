class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size();
        int m = units[0].size();
        long long sum = 0;
        if(m == 1) {
            for(auto &i: units) {
                sum += i[0];
            }
            return sum;
        }
        for(auto &i: units) {
            sort(i.begin(),i.end());
        }
        int ind = 0;
        long long mini = 1e18;
        for(int i = 0; i<n; i++) {
            if(units[i][1] < units[ind][1]) {
                ind = i;
            }
            mini = min(mini,1ll*units[i][0]);
            sum += units[i][1];
        }
        sum -= units[ind][1];
        sum += mini;
        return sum;
    }
};