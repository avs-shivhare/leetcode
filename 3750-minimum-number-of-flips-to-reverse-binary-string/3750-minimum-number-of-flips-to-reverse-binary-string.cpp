class Solution {
public:
    string bin(long long n) {
        string s = "";
        while(n) {
            if(n&1) s+= '1';
            else s += '0';
            n >>= 1;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int minimumFlips(int n) {
        string s = bin(n);
        int l = 0, r = s.size()-1;
        int ans = 0;
        while(l<r) {
            if(s[l] != s[r]) ans += 2;
            l++;
            r--;
        }
        return ans;
    }
};