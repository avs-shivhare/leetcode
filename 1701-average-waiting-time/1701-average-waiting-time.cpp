class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        double ans = 0;
        int time = 0;
        for(auto i: cust) {
            if(i[0] > time) {
                time = i[0];
            }
            ans += (time+i[1])-i[0];
            time += i[1];
        }
        return ans/cust.size();
    }
};