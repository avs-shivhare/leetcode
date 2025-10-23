class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2) {
            string ans = "";
            int n = s.size();
            for(int i = 1; i<n; i++) {
                ans += ((s[i-1]-'0')+(s[i]-'0'))%10+'0';
            }
            s = ans;
        }
        //cout<<s<<endl;
        return s[0] == s[1];
    }
};