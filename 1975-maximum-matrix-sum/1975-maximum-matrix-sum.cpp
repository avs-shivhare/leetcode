class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int cnt = 0;
        for(auto &i: matrix) {
            for(auto &j: i) {
                if(j<=0) {
                    cnt++;
                    mini = max(mini,j);
                }
                else maxi = min(maxi,j);
                ans += abs(j);
            }
        }
        if(cnt&1) {
            ans -= 2*min(maxi,abs(mini));
        }
        return ans;
    }
};