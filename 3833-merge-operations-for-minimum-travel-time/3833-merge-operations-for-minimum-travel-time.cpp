class Solution {
public:
    vector<vector<vector<int>>> dp;
    int find(int i,int cnt,int ti,vector<int> &pos,vector<int> &t,int &k) {
        if(i >= pos.size()-1) {
            //cout<<cnt<<endl;
            if(cnt == k) return 0;
            return 1e9;
        }
        if(dp[i][ti][cnt] != -1) return dp[i][ti][cnt];
        int ans = 1e9;
        int count = 0;
        int time = 0;
        for(int j = i+1; j<pos.size(); j++) {
            time += t[j];
            if(cnt+count<=k) {
                int dist = pos[j]-pos[i];
                int temp = dist*ti+find(j,cnt+count,time,pos,t,k);
                // cout<<dist<<" "<<time<<endl;
                // cout<<i<<" -> "<<j<<" "<<temp<<" "<<dist*time<<endl;
                ans = min(ans,temp);
            }
            count++;
        }
        return dp[i][ti][cnt] = ans;
    }
    int minTravelTime(int l, int n, int k, vector<int>& pos, vector<int>& time) {
        int sum = accumulate(time.begin(),time.end(),0);
        dp.resize(n,vector<vector<int>>(sum+1,vector<int>(11,-1)));
        return find(0,0,time[0],pos,time,k);
    }
};