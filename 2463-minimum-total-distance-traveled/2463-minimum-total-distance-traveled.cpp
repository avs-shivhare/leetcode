class Solution {
public:
    long long dp[101][101][101];
    long long find(int i,int j,int cnt,vector<int> &robot,vector<vector<int>> &fact) {
        if(i == robot.size()) return 0;
        if(j == fact.size()) return 1e18;
        if(dp[i][j][cnt] != -1) return dp[i][j][cnt];
        long long take = 1e18,notTake = 1e18;
        if(fact[j][1] > cnt) {
            //cout<<robot[i]<<" "<<fact[j][0]<<" abs "<<i<<" "<<j<<endl;
            take = abs(robot[i]-fact[j][0])+find(i+1,j,cnt+1,robot,fact);
        }
        notTake = find(i,j+1,0,robot,fact);
        //cout<<i<<" "<<j<<" "<<take<<" "<<notTake<<endl;
        return dp[i][j][cnt] = min(take,notTake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& fact) {
        memset(dp,-1,sizeof(dp));
        sort(robot.begin(),robot.end());
        sort(fact.begin(),fact.end());
        return find(0,0,0,robot,fact);
    }
};