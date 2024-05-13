class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(auto i: bookings) {
            int start = i[0];
            int end = i[1];
            int cost = i[2];
            for(int j = start-1; j< end; j++) {
                ans[j] += cost;
            }
        }
        return ans;
    }
};