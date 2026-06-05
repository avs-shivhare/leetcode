class Solution {
public:
    long long dp[21][11][11][2];
    long long dp1[21][11][11][2];
    pair<long long,long long> find(int i,int last,int slast,int tight,int start,string &s) {
        if(i >= s.size()) return {1,0};
        if(!tight && dp[i][last][slast][start] != -1) return {dp[i][last][slast][start],dp1[i][last][slast][start]};
        int limit = tight ? s[i]-'0': 9;
        long long cnt = 0,ans = 0;
        for(int j = 0; j<=limit; j++) {
            int ntight = tight && (j == limit);
            if(!start && j == 0) {
                auto x = find(i+1,10,10,ntight,0,s);
                cnt += x.first;
                ans += x.second;
            }
            else {
                long long add = 0;
                if(start && slast != 10) {
                    if((slast < last && last > j) || (slast > last && last < j)) {
                        add = 1;
                    }
                }
                int nslast = start ? last : 10;
                int nlast = j;
                auto x = find(i+1,nlast,nslast,ntight,1,s);
                cnt += x.first;
                ans += x.second+add*x.first;
            }
        }
        if(!tight) {
            dp[i][last][slast][start] = cnt;
            dp1[i][last][slast][start] = ans;
        }
        return {cnt,ans};
    }
    long long query(long long n) {
        if(n < 0) return 0;
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        memset(dp1,-1,sizeof(dp1));
        return find(0,10,10,1,0,s).second;
    }
    long long totalWaviness(long long num1, long long num2) {
        return query(num2)-query(num1-1);
    }
};