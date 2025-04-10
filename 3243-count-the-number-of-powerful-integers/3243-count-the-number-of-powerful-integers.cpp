class Solution {
public:
    long long dp[18][2];
    long long find(int i,bool t,string &x,int &limit,string &s) {
        if(s.size() > x.size()) return 0;
        if(i == x.size()) return 1;
        if(dp[i][t] != -1) return dp[i][t];
        long long ans = 0;
        int rem = x.size()-s.size();
        if(i < rem) {
            if(t) {
                for(int curr = 0; curr <= min(limit, (x[i]-'0')); curr++) {
                    if(curr == (x[i]-'0')) ans += find(i+1,true,x,limit,s);
                    else ans += find(i+1,false,x,limit,s);
                }
            }
            else {
                for(int curr = 0; curr<= limit; curr++) {
                    ans += find(i+1,false,x,limit,s);
                }
            }
        }
        else {
            int ind = i-rem;
            //cout<<ind<<" "<<i<<" "<<rem<<endl;
            int digit = s[ind]-'0';
            if(digit <= limit) {
                if(t) {
                    if(digit == (x[i]-'0')) ans += find(i+1,true,x,limit,s);
                    else if(digit < (x[i]-'0')) ans += find(i+1,false,x,limit,s);
                } 
                else {
                    ans += find(i+1,false,x,limit,s);
                }
            }
        }
        return dp[i][t] = ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string r = to_string(finish);
        string l = to_string(start-1);
        if(r.size() < s.size()) return 0;
        memset(dp,-1,sizeof(dp));
        long long ans = find(0,true,r,limit,s);
        memset(dp,-1,sizeof(dp));
        long long temp = find(0,true,l,limit,s);
        //cout<<ans<<" "<<temp<<endl;
        return ans-temp; 
    }
};