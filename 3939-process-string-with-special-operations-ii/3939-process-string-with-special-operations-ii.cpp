class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for(auto i: s) {
            if('a'<= i && i <= 'z') len++;
            else if(i == '*') {
                if(len > 0) len--;
            }
            else if(i == '#') len *= 2ll;
        }
        if(k >= len) return '.';
        int n = s.size();
        for(int i = n-1; i>=0; i--) {
            if('a' <= s[i] && s[i] <= 'z') {
                len--;
                if(k == len) return s[i];
            }
            else if(s[i] == '*') len++;
            else if(s[i] == '#') {
                len /= 2;
                if(k >= len) k -= len;
            }
            else {
                k = len-1-k;
            }
        }
        return '.';
    }
};