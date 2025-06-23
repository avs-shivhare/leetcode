class Solution {
public:
    bool check(string x) {
        int l = 0,r = x.size()-1;
        //if(x[l] == '0' || x[r] == '0') return false;
        while(l<r) {
            if(x[l] != x[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string kth(long long x,long long k) {
        string ans = "";
        while(x) {
            ans += to_string(x%k);
            x /= k;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    long long kMirror(int k, int n) {
        int cnt = 0;
        long long ans = 0;
        long long l = 1;
        while(cnt < n) {
            long long r = l*10;
            for(int i = 0; i<2; i++) {
                for(int x = l; x<r && cnt < n; x++) {
                    long long p = x;
                    long long z = (i == 0? x/10: x);
                    while(z) {
                        p = p*10+(z%10);
                        z /= 10;
                    }
                    string v = kth(p,k);
                    if(check(v)) {
                        ans += p;
                        cnt++;
                    }
                }
            }
            l = r;
        }
        return ans;
    }
};