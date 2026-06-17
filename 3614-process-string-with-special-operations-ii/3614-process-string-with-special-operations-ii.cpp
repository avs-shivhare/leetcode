class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for(auto &i: s) {
            if(i == '*') len = max(0ll,len-1);
            else if(i == '#') len += len;
            else if(i != '%') len++;
        }
        if(k >= len) return '.';
        for(int i = s.size()-1; i>=0; i--) {
            if(s[i] == '*') {
                len++;
            }
            else if(s[i] == '#') {
                len >>= 1;
                if(k >= len) k = max(0ll,k-len);
            }
            else if(s[i] == '%') k = len-k-1;
            else len--;
            //cout<<len<<" "<<k<<" "<<i<<endl;
            if(k >= len) return s[i];
        }
        return '.';
    }
};