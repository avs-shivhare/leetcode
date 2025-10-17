class Solution {
public:
    unordered_map<long long,int> dp;
    long long find(long long i,long long last,int can,string &s,int &k) {
        if(i == s.size()) return 0;
        long long key = (i<<30) | (last<<1) | can;
        if(dp.find(key) != dp.end()) return dp[key];
        long long ans = 0;
        int ind = s[i]-'a';
        long long newMask = last | (1ll<<ind);
        if(__builtin_popcountll(newMask) > k) {
            ans = 1+find(i+1,1ll<<ind,can,s,k);
        }
        else ans = find(i+1,newMask,can,s,k);
        if(can) {
            for(int j = 0; j<26; j++) {
                long long newM = last | (1ll<<j);
                if(__builtin_popcountll(newM) > k) {
                    ans = max(1+find(i+1,1ll<<j,0,s,k),ans);
                }
                else {
                    ans = max(ans,find(i+1,newM,0,s,k));
                }
            }
        }
        return dp[key] = ans;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        dp.clear();
        return find(0,0,1,s,k)+1;
    }
};