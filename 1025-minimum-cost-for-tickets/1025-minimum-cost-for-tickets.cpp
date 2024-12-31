class Solution {
public:
    int dp[366][31];
    int find(int i,int rem,vector<int> &day,vector<int> &cost) {
        if(i == day.size()) return 0;
        if(dp[i][rem] != -1) return dp[i][rem];
        int one = 1e9,two = 1e9,three = 1e9,notTake = 1e9;
        bool flag = false;
        if(rem) {
            if(rem >= day[i]-day[i-1]) {
                notTake = 0+find(i+1,rem-(day[i]-day[i-1]),day,cost);
                flag = true;
            }
        }
        if(!flag) {
            one = cost[0]+find(i+1,0,day,cost);
            two = cost[1]+find(i+1,6,day,cost);
            three = cost[2]+find(i+1,29,day,cost);
        }
        return dp[i][rem] = min({one,two,three,notTake});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,days,costs);
    }
};