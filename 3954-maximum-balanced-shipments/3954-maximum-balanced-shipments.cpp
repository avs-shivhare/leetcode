class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int cnt = 0;
        int maxi = -1e9;
        for(auto i: weight) {
            if(i < maxi) {
                cnt++;
                maxi = -1e9;
            }
            else {
                maxi = max(maxi,i);
            }
        }
        return cnt;
    }
};