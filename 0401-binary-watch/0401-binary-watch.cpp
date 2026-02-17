class Solution {
public:
    vector<string> ans;
    int dp[100][100];
    void find(int h,int m,int cnt) {
        //cout<<h<<" "<<m<<" "<<cnt<<endl;
        if(h > 11 || m > 59) return;
        if(dp[h][m] != -1) return;
        if(cnt == 0) {
            string mm = to_string(m);
            if(mm.size() != 2) mm = "0"+mm;
            ans.push_back(to_string(h)+":"+mm);
            dp[h][m] = 1;
            return;
        }
        for(int i = 0; i<4; i++) {
            //cout<<i<<" i"<<endl;
            if(!(h&(1<<i))) find(h|(1<<i),m,cnt-1);
        }
        for(int j = 0; j<6; j++) {
            //cout<<j<<" j"<<endl;
            if(!(m&(1<<j))) find(h,m|(1<<j),cnt-1);
        }
        dp[h][m] = 1;
        return;
    }
    vector<string> readBinaryWatch(int t) {
        memset(dp,-1,sizeof(dp));
        find(0,0,t);
        sort(ans.begin(),ans.end());
        return ans;
    }
};