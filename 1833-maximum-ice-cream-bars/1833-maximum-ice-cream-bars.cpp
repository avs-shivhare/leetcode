class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt = 0;
        for(auto &i: costs) {
            if(i > coins) break;
            cnt++;
            coins -= i;
        }
        return cnt;
    }
};