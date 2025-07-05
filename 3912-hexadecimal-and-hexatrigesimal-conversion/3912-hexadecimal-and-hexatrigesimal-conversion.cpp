class Solution {
public:
    string dtoh(long long x) {
        string bi = "";
        while(x) {
            bi += (x&1 ? '1': '0');
            x = x>>1;
        }
        reverse(bi.begin(),bi.end());
        string ans = "";
        int last = bi.size();
        for(int i = max((int)bi.size()-4,0); i>=0; i = (i > 0 ? max(0,i-4):i-4)) {
            string x = bi.substr(i,last);
            last -= 4;
            while(x.size() < 4) {
                x = '0'+x;
            }
            int sum = 0;
            for(int j = 0; j<4; j++) {
                if(x[4-j-1] == '1') {
                    sum |= 1<<j;
                }
            }
            if(sum >= 10) {
                ans += (sum-10)+'A';
            } 
            else ans += sum+'0';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string dtohh(long long n) {
        string ans = "";
        while(n) {
            int rem = n%36;
            n /= 36;
            //cout<<n<<" "<<rem<<endl;
            if(rem >= 10) {
                ans += (rem-10)+'A';
            }
            else ans += rem+'0';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string concatHex36(int n) {
        long long x = (long long)n*(long long)n;
        return dtoh(x)+dtohh(x*n);
    }
};