class Solution {
public:
    int mod = 1e6+1;
    long long find(vector<int> &mpp,int n) {
        long long res = 1;
        for(int i = 0; i<26; i++) {
            long long way = 1;
            int c = mpp[i]>>1;
            if(c == 0) continue;
            c = min(c,n-c);
            for(int j = 1; j<=c; j++) {
                way = way*(1ll*n-j+1)/j;
                if(way >= mod) way = mod;
            }
            res *= way;
            if(res >= mod) return mod;
            n -= mpp[i]>>1;
        }
        return res;
    }
    string smallestPalindrome(string s, int k) {
        vector<int> mpp(26,0);
        int n = s.size();
        for(auto &i: s) mpp[i-'a']++;
        char odd = '1';
        int cnt = 0;
        for(int i = 0; i<26; i++) {
            if(mpp[i]&1) odd = i+'a';
            cnt += mpp[i]>>1;
        }
        long long total = find(mpp,cnt);
        if(total < k) return "";
        string ans = "";
        while(cnt) {
            for(int i = 0; i<26; i++) {
                if(!(mpp[i]>>1)) continue;
                mpp[i] -= 2;
                long long t = find(mpp,(cnt > 0? cnt-1: 0));
                mpp[i] += 2;
                //cout<<t<<" "<<k<<endl;
                if(t >= k) {
                    ans += i+'a';
                    mpp[i]-= 2;
                    //temp += t;
                    cnt--;
                    break;
                }
                else {
                    k -= t;
                }
            }
            // cout<<temp<<endl;
            //cout<<ans<<endl;
        }
        string t = ans;
        reverse(t.begin(),t.end());
        if(odd == '1') return ans+t;
        return ans+odd+t;
    }
};